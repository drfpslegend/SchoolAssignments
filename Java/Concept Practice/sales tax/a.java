import java.util.Scanner;

public class a
{
	public static void main(String[] args)
	{
		String month;
		int year;
		double endTotal;
		double subTotal, countyTotal, stateTotal, taxTotal;
		double countyRate = 0.031, stateRate = 0.0675;
		Scanner in = new Scanner(System.in);
		
		System.out.print("Enter the current sales month: ");
		month = in.next();
		System.out.print("Enter the current sales year: ");
		year = in.nextInt();
		System.out.print("Enter the total end amount earned for the month you entered: ");
		endTotal = in.nextDouble();
		
		subTotal = endTotal / (1 + countyRate + stateRate);
		countyTotal = subTotal * countyRate;
		stateTotal = subTotal * stateRate;
		taxTotal = countyTotal + stateTotal;
		
		System.out.println("\nMonth: " + month + " " + year);
		System.out.println("----------------------------");
		System.out.printf("End Total: \t$ %10.2f %n", endTotal);
		System.out.printf("Sub Total: \t$ %10.2f %n", subTotal);
		System.out.printf("County Total: \t$ %10.2f %n", countyTotal);
		System.out.printf("State Total: \t$ %10.2f %n", stateTotal);
		System.out.printf("Tax Total: \t$ %10.2f %n", taxTotal);
	}
}