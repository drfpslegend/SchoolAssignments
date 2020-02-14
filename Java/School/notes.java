// spring framework, just a note from something that was mentioned in class
// zerox park

import java.util.Scanner; // use of the scanner class
import java.util.ArrayList; // use of the ArrayList class
import java.io.File; // use of file class
import java.io.PrintWriter; // use of file writing class

System.out.print(""); // system print function
// common System.out functions:
// print()
// println()
// printf()

byte x1; short x2; int x3; long x4; float x5; double x6; char x7; boolean x8; // native data types

String x9; // string class
// common String functions:
// charAt()
// compare(String)

Scanner in = new Scanner (System.in); // Scanner class, initialized with the particular object you want
// common Scanner functions:
// next()
// nextLine()
// nextInt()
// nextDouble()
// hasNext()
// hasNextLine()
// hasNextInt()
// hasNextDouble()

int x10 = Math.pow(2, 4); // an example Math function
// common Math functions:
// pow()
// sin(), cos(), tan(), ...
// log(), exp()



// basic outline of the main function inside the wrapper class

import java.io.FileNotFoundException; // use of the FileNotFoundException (keyword?)

public class notes
{
	public static void main(String[] args) throws FileNotFoundException
	{		
		System.out.print("Enter a character: ");
		char c = in.next().charAt(0); // uses the next().charAt(0) member function to store user input for the variable c
		
		int size = 10;
		double [] array = new double [size]; // array declaration syntax
		
		ArrayList<Integer> myList = new ArrayList<Integer>(); // array list syntax (vector in c++)
		myList.add(5);
		myList.add(10);
		
		File sourceFile1 = new File("input.txt"); // to read text from a file
		Scanner inFile = new Scanner(sourceFile1); // can use the scanner class to read data from a file instead of from user input
		System.out.print("File values: ");
		while (inFile.hasNextInt())
		{
			int num = inFile.nextInt();
			System.out.printf("%d ", num);
		}
		inFile.close(); // close the file after using it
		
		PrintWriter outFile = new PrintWriter("output.txt"); // to write text to a file
		outFile.printf("%s", "Hello world!");
		outFile.close(); // close the file after using it
	}
	
	public static String isPerfect(int n) // function syntax
	{
		int sum = 0;
		String factors = "";
		for (int i = 1; i <= n - 1; ++i)
		{
			if (n % i == 0)
			{
				factors = factors + "_" + i;
				sum += i;
			}
		}
		if (sum == n)
		{
			return factors;
		}
		else
		{
			return null;
		}
	}
}