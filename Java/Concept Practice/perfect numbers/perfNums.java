import java.util.Scanner;

public class perfNums
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		
		System.out.printf("Enter an upper bound to check for perfect numbers: ");
		int userNum = in.nextInt();
		System.out.printf("\nChecking . . .\n\n");
		
		for (int i = 1; i <= userNum; ++i) 
		{
			String factorList = isPerfect(i);
			if (factorList != null)
			{
				System.out.printf("%d is a perfect number!\n\t%d = ", i, i);
				for (int j = 1; j <= i - 1; ++j)
				{
					if (j == 1)
					{
						System.out.printf("%d", j);
					}
					else if (factorList.contains("" + j))
					{
						System.out.printf(" + %d", j);
					}
				}
				System.out.printf("\n");
			}
		}
	}
	
	public static String isPerfect(int n)
	{
		int sum = 0;
		String factors = "";
		for (int i = 1; i <= n - 1; ++i)
		{
			if (n % i == 0)
			{
				factors = factors + "_" + i; // update the string of factors
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