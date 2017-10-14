#include <iostream>
#include "jni.h"
#include "HelloJni.h"

using namespace std;

/*
 *   Class:     HelloJni
 *   Method:    displayHello
 *   Signature: ()V
 */
JNIEXPORT void JNICALL Java_HelloJni_displayHello
  (JNIEnv *, jobject)
{
	cout << "Hello java JNI method."<<endl;
}
