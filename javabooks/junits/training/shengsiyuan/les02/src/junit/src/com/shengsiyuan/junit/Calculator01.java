package com.shengsiyuan.junit;

public class Calculator01 {

	public int add(int a, int b) {
		return a + b;
	}
	
	public int substract(int a, int b) {
		return a - b;
	}
	
	public int multiply(int a, int b) {
		return a * b;
	}
	
	public int divide(int a, int b) {
		return a / b;
	}
	
	// 传统的测试方法。	
	public static void main(String args[]) {
		Calculator01 cal = new Calculator01();
		
		int a = cal.add(1, 2);
		System.out.println(a);
		
		int b = cal.substract(1, 2);
		System.out.println(b);
		
		int c = cal.multiply(1, 3);
		System.out.println(c);
		
		int d = cal.divide(1, 5);
		System.out.println(d);
	}
}
