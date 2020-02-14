import java.util.Scanner;

public class a
{
	public static void main(String[] args)
	{
		int min, max;
		int first, second, third, fourth;
		Scanner in = new Scanner(System.in);
		
		System.out.print("Enter the first integer: ");
		first = in.nextInt();
		min = first;
		max = first;
		System.out.print("Enter the second integer: ");
		second= in.nextInt();
		if (second < min)
		{
			min = second;
		}
		if (second > max)
		{
			max = second;
		}
		System.out.print("Enter the third integer: ");
		third = in.nextInt();
		if (third < min)
		{
			min = third;
		}
		if (third > max)
		{
			max = third;
		}
		System.out.print("Enter the fourth integer: ");
		fourth = in.nextInt();
		if (fourth < min)
		{
			min = fourth;
		}
		if (fourth > max)
		{
			max = fourth;
		}
		System.out.printf("%n");
		
		System.out.println("The numbers you entered are " + first + ", " + second + ", " + third + ", " + fourth);
		System.out.println("The minimum of your numbers is " + min);
		System.out.println("The maximum of your numbers is " + max);
	}
}