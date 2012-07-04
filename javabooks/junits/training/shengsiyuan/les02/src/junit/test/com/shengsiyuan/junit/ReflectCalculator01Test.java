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
public class ReflectCalculator01Test extends TestCase {
	
	@Override
	public void setUp() throws Exception {
		System.out.println("set up");
	}
	
	@Override
	public void tearDown() throws Exception {
		System.out.println("tear down");
	}
	public void testAdd () {
		Calculator01 cal = new Calculator01();
		
		int result = cal.add(1, 2);
		
		Assert.assertEquals(3, result);
	}
	
	public void testSubstract() {
		Calculator01 cal = new Calculator01();
		
		int result = cal.substract(1, 2);
		
		Assert.assertEquals(-1, result);
	}
	
	public void testMultiply() {
		Calculator01 cal = new Calculator01();
		
		int result = cal.multiply(2, 3);
		
		Assert.assertEquals(6, result);
	}
	
	public void testDivide() {
		Calculator01 cal = new Calculator01();
		
		int result = cal.divide(6, 2);
		
		Assert.assertEquals(3, result);
	}
	
/*	public void testDivideDivideByZero() {
		Calculator01 cal = new Calculator01();
		
		cal.divide(6, 0);
	}*/
}
