package com.ggggght.jni_feature;

public class ParametersJNI {
	static {
		System.load("/Users/admin/github/JNI_Java/app/src/main/java/com/ggggght/jni_feature/libnative.dylib");
	}

	public static void main(String[] args) {
		System.out.println("Java: My full name: " + new ParametersJNI().sayHelloToMe("Martin", false));
		long sumFromNative = new ParametersJNI().sumIntegers(456, 44);
		System.out.println("Java: The sum coming from native code is: " + sumFromNative);
	}

	private native long sumIntegers(int first, int second);

	private native String sayHelloToMe(String name, boolean isFemale);
}
