import java.util.Scanner;

public class a
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		System.out.print("How many days will the pay double: ");
		int days = in.nextInt();
		System.out.printf("%n");
		
		double total = 0.01;
		System.out.printf("%-20s %-20s %n", "Day", "Total pay");
		System.out.println("----------------------------------------");
		for (int i = 1; i <= days; ++i)
		{
			System.out.printf("%-19d %1s %18.2f %n", i, "$", total);
			total += total;
		}
	}
}