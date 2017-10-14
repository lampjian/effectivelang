import java.util.List;
import java.util.ArrayList;
import java.util.UUID;
import net.sf.cglib.proxy.Enhancer;
import net.sf.cglib.proxy.MethodInterceptor;
import net.sf.cglib.proxy.MethodProxy;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

public class PergenOutOfMem {


	public static void main(String[] args) {
		//testPergenOutOfMem1();
		//testPergenOutOfMem2();
		testPergenOutOfMem3();
	}

	public static void testPergenOutOfMem1() {
		// try filld up constant pool with String constant failed, after jdk7 constant pool put in heap, also can gc.
		List<String> list = new ArrayList<String>();

		while(true) {
			list.add(UUID.randomUUID().toString().intern());
		}
	}

	public static void testPergenOutOfMem2() {
		// try using cglib fill up OldGen with Class
		try {
			while(true) {
				Enhancer enhancer = new Enhancer();
				//enhancer.setSuperclass(OOM.class);
				enhancer.setSuperclass(OOM.class);
				enhancer.setUseCache(false);
				enhancer.setCallback(new MethodInterceptor() {
					@Override
					public Object intercept(Object obj, Method method, Object[] args, MethodProxy proxy) throws Throwable {
						return proxy.invokeSuper(obj,args);
					}
				});
				enhancer.create();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	public static void testPergenOutOfMem3() {

		while(true) {
			final OOM oom = new OOM();
			Proxy.newProxyInstance(oom.getClass().getClassLoader(), oom.getClass(), new InvocationHandler() {
				public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
					Object result = method.invoke(oom.args);
					return result;
				}
			});

		}
	}
}


class OOM {}

