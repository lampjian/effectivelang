// package dynamic.proxy;
import java.io.FileOutputStream;
import java.io.IOException;
import sun.misc.ProxyGenerator;

/**
 * 代理类的生成工具
 * @author zyb
 * @since 2012-8-9
 */
class ProxyGeneratorUtils {
	/**
	 * 把代理类的字节码写到硬盘上
	 * @param path 保存路径
	 */
	public static void writeProxyClassToHardDisk(String path) {
		// 第一种方法，这种方式在刚才分析ProxyGenerator时已经知道了
		//System.getProperties().put("sun.misc.ProxyGenerator.saveGeneratedFiles", true);
		
		// 第二种方法
		
		// 获取代理类的字节码
		byte[] classFile = ProxyGenerator.generateProxyClass("$Proxy11",UserServiceImpl.class.getInterfaces());
		
		FileOutputStream out = null;
		
		try {
			out = new FileOutputStream(path);
			out.write(classFile);
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				out.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}

// package dynamic.proxy;
// import org.junit.Test;
/**
 * 动态代理测试类
 * @author zyb
 * @since 2012-8-9
 *
 */
class ProxyTest2 {
//	@Test
	public void testProxy2() throws Throwable {
		// 实例化目标对象
		UserService userService = new UserServiceImpl();
		
		// 实例化InvocationHandler
		MyInvocationHandler invocationHandler = new MyInvocationHandler(userService);
		
		// 根据目标对象生成代理对象
		UserService proxy = (UserService) invocationHandler.getProxy();
		
		// 调用代理对象的方法
		proxy.add();
		
	}
	
//	@Test
	public void testGenerateProxyClass() {
		ProxyGeneratorUtils.writeProxyClassToHardDisk("/home/ubuntu/$Proxy11.class");
	}
}
