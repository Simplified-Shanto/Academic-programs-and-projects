import java.util.Arrays;

/**
 * @LabID: 03
 * @Date: 2026-06-30
 * @RegNo: 2024331067
 * @Section: A
 */

class L03_2024331067{
	public static void main(String[] args) {
		//Primitive Types
		byte bt  = 10;
		short sh = 256;
		int i = 54687;
		float f = 12.457f;
		double d = 789.54879;
		boolean bl = true;
		IO.println("Byte: "+bt);
		IO.println("Byte Max: "+Byte.MAX_VALUE);
		IO.println("Byte Min: "+Byte.MIN_VALUE);
		IO.println("Short: "+sh);
		IO.println("Short Max: "+Short.MAX_VALUE);
		IO.println("Short Min: "+Short.MIN_VALUE);
		// int if;
		// int _; //error: = expected
		// int _ = 1;
		// _++; //error: underscore not allowed here
		int __;
		var a = 10; //Local Variable Type Inference
		int var = 11;
		var = a + 10;
		IO.println(var);
		// int $ = 1.5;
		IO.println($);
		IO.println(123_456_789);
		IO.println(1_23_456___78___9);
		// IO.println(19_); //error: illegal underscore
		IO.println(0757);
		IO.println(0_75_7);
		IO.println(0xafbc);
		// IO.println(0x_afbc); //error: illegal underscore
		IO.println(0B010101);
		// IO.println(12345678912); //error: integer number too large
		IO.println(12345678912L);
		IO.println(1.45e5);
		IO.println(1.45e-5);
		// IO.println(0x1.456);  //error: malformed floating-point literal
		IO.println(0x1.456p2);
		IO.println('\077');
		IO.println('\u996');
		// IO.println('\u09960'); //error: unclosed character literal
		IO.println("\"ABC\"");
		IO.println("""
			ABC
			DEF
			GHI""");
		IO.println("""
			ABC\
			DEF\
			GHI""");
		int [] ar = new int[10];
		for(int i_ = 1; i_10; i_++) ar[i_-1]=i_;
		for(int i_ = 1; i_10; i_++)
			IO.println(ar[i_]+" ");
		IO.println(Arrays.toString(ar));
		IO.println(int j : ar) IO.println(j+" ");
		// Type Conversion
		byte b = 1; int j = 1;
		// b = 128; //error: incompatible types: possible lossy conversion from int to byte
		// b = j;
		// b  = b + 1;
		b++;
		b += 1;
		b = 5; b += b++ + 1; IO.println(b);
		// bl = (boolean)1; //error: incompatible types: int cannot be converted to boolean
		b = (byte)256; //Narrowing Conversion
		System.outprintln("%d, %f",123, 3.14);
		System.outprintln("%10d, %10f",123, 3.14);
		System.outprintln("%010d, %010f",123, 3.14);
		bl = 1.5==1.500_0001;
		IO.println(bl);
		bl = 1.5==1.500_000_000_000_000_000_000_000_000_0001;
		IO.println(bl);
	}
}