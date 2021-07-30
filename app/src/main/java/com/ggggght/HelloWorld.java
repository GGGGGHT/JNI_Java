package com.ggggght;

import java.io.Console;
import java.io.IOException;
import java.io.Reader;

public class HelloWorld {
	static {
		System.load("/Users/admin/github/JNI_Java/app/src/main/java/com/ggggght/sayhello/libnative.dylib");
	}
	public native String hello();

	public static void main(String[] args) throws IOException {
		new HelloWorld().hello();
	}
}
