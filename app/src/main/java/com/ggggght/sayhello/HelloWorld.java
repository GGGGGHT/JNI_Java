package com.ggggght.sayhello;

import java.io.IOException;

public class HelloWorld {
	static {
		// System.load("/Users/admin/github/JNI_Java/app/src/main/java/com/ggggght/sayhello/libnative.dylib");
		System.loadLibrary("native");
	}
	public native String hello();

	public static void main(String[] args) throws IOException {
		new HelloWorld().hello();
	}
}
