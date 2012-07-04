package com.shengsiyuan.junit;

import junit.framework.Assert;
import junit.framework.TestCase;

/**
 * ���������Ҫ�̳��� TestCase ��
 * @author Administrator
 *
 * �� JUnit 3.8 �У����Է�����Ҫ��������ԭ��
 * 
 * 1. ���η� public
 * 2. ����ֵ void
 * 3. �޷�������
 * 4. �������Ʊ����� test ��ͷ
 *
 */
public class Reflect01Calculator01Test extends TestCase {
	
	private Calculator01 cal;
	@Override
	public void setUp() throws Exception {
		cal = new Calculator01();
	}
	
	@Override
	public void tearDown() throws Exception {
		System.out.println("tear down");
	}
	public void testAdd () {
		int result = cal.add(1, 2);
		
		Assert.assertEquals(3, result);
	}
	
	public void testSubstract() {
		int result = cal.substract(1, 2);
		
		Assert.assertEquals(-1, result);
	}
	
	public void testMultiply() {
		int result = cal.multiply(2, 3);
		
		Assert.assertEquals(6, result);
	}
	
	public void testDivide() {
		int result = cal.divide(6, 2);
		
		Assert.assertEquals(3, result);
	}
	
/*	public void testDivideDivideByZero() {
		Calculator01 cal = new Calculator01();
		
		cal.divide(6, 0);
	}*/
}
