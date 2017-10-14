export CLASSPATH=$CLASSPATH:./cglib-nodep-3.2.5.jar:.

java -Xmx5m -XX:MaxDirectMemorySize=5m -XX:+PrintGCDetails $1

