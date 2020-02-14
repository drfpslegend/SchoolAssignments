import java.util.Scanner;

public class sda
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		
		// get number of values from user
		System.out.print("Enter the size of your list of numbers: ");
		int size = in.nextInt();
		double [] userArray = new double [size];
		
		// get values from user
		for (int i = 0; i < size; ++i)
		{
			System.out.printf("%d) Enter a number: ", i + 1);
			userArray[i] = in.nextDouble();
		}
		
		// calculate minimum
		double min = userArray[0];
		for (int i = 1; i < size; ++i)
		{
			if (userArray[i] < min)
			{
				min = userArray[i];
			}
		}
		System.out.println("\nMinimum: " + min);
		
		// calculate maximum
		double max = userArray[0];
		for (int i = 1; i < size; ++i)
		{
			if (userArray[i] > max)
			{
				max = userArray[i];
			}
		}
		System.out.println("Maximum: " + max);
		
		// calculate average
		double average = 0.0;
		for (int i = 0; i < size; ++i)
		{
			average += userArray[i];
		}
		average /= size;
		System.out.println("Average: " + average);
		
		// calculate population standard deviation
		double [] squaredDifferences = new double[size];
		double populationVariance = 0.0;
		double populationStd = 0.0;
		for (int i = 0; i < size; ++i)
		{
			squaredDifferences[i] = Math.pow(userArray[i] - average, 2);
		}
		for (int i = 0; i < size; ++i)
		{
			populationVariance += squaredDifferences[i];
		}
		populationVariance /= size;
		populationStd = Math.sqrt(populationVariance);
		System.out.println("Population standard deviation: " + populationStd);
		
		// calculate sample standard deviation
		double sampleVariance = 0.0;
		double sampleStd = 0.0;
		for (int i = 0; i < size; ++i)
		{
			sampleVariance += squaredDifferences[i];
		}
		sampleVariance /= (size - 1);
		sampleStd = Math.sqrt(sampleVariance);
		System.out.println("Sample standard deviation: " + sampleStd);
	}
}