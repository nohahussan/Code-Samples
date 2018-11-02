/**
 * Weather Class
 * answer to assignment no 1, 60-212 summer 2014
 * This class represents the local weather.
 */

/**
 * @author Noha Hussan
 * @studentNumber 104151495
 * @section 52
 * @email hussna@uwindsor.ca
 */
public class Weather 
{
	// Instance Variables
	private double tempC; 		//temperature in °C
	private double windSpeed; 	//wind speed in km/h
	private double windChill; 	//wind chill factor
	private boolean isSevere; 	//indicates if the coldness is severe
	
	// Constructors
	/**
	 * Weather, no argument constructor, creates a weather object with
	 * default values of temperature 20 c, and windspeed of 0 km/h
	 * @param non
	 */
	public Weather() 
	{
		setTempC(20);
		setWindSpeed(0);
	}
	
	/**
	 * Weather object constructor with two arguments
	 * @param tempC
	 * @param windSpeed
	 */
	public Weather (double tempC, double windSpeed)
	{
		setTempC(tempC);
		setWindSpeed(windSpeed);
	}
	
	// Public Methods
	/**
	 * setTempC , sets the value of the instance variable tempC
	 * @param tempC
	 */
	public void setTempC(double tempC) 
	{
		if (isValidTemprature(tempC))
		{
			this.tempC = tempC;
			setWindchill();
			setSeverity();
		}
		else
		{
			System.out.println("Invalid temperature");
			System.exit(0);
		}
	}
	
	/**
	 * sets the value of the instance variable windSpeed
	 * @param windSpeed
	 */
	public void setWindSpeed(double windSpeed) 
	{
		if (isValidWindSpeed(windSpeed))
		{
			this.windSpeed = windSpeed;
			setWindchill();
			setSeverity();
		}
		else
		{
			System.out.println("Invalid wind speed");
			System.exit(0);
		}
	}
	
	/**
	 * getTempC, returns the value of air temperature
	 * @return tempC
	 */
	public double getTempC() {
		return tempC;
	}

	/**
	 * getWindSpeed, returns the value of air speed
	 * @return windSpeed
	 */
	public double getWindSpeed() {
		return windSpeed;
	}

	/**
	 * getWindChill, returns the value of the claculated windChill
	 * @return windChill
	 */
	public double getWindChill() {
		return windChill;
	}
	
	/**
	 * getSeverity, returns the value of the severity
	 * @return isSevere
	 */
	public boolean getSeverity()
	{
		return isSevere;
	}
	
	/**
	 * returns a sting representing the object
	 */
	public String toString()
	{
		String objectString;
		if (isSevere)
			objectString = "Current temperature is " + (int)tempC + " °C, feels like " + (int)windChill+ " °C (severely cold), with a wind speed of " + (int)windSpeed + " km/h";
		else
			objectString = "Current temperature is " + (int)tempC + " °C, feels like " + (int)windChill+ " °C, with a wind speed of " + (int)windSpeed + " km/h";

		return objectString;
	}
	
	// Private Methods
	/*
	 * setWindchill
	 * calculates the windChill temperature based
	 * on the values of tempC and windSpeed
	 */
	private void setWindchill()
	{
		// windChill is calculated according to the equation for
		// speeds at or above 5 km/h and 
		// temperature at or below 10 c
		if (tempC <= 10 && windSpeed >= 5)
			windChill = 13.12 + (0.6215 * tempC) 
				      - (11.37 * Math.pow(windSpeed, 0.16))
				      + (0.3965 * tempC * Math.pow(windSpeed, 0.16));
		
		else // otherwise it is equal to temperature
			windChill = tempC;
	}
	
	/*
	 * setSeverity
	 * sets the weather severity based on windchill calculation
	 */
	private void setSeverity()
	{
		// If Wind Chill is less than -26 C,
		// it is considered as severe, (isSevere = true)
		if (windChill < -26)
			isSevere = true;
		else
			isSevere = false;
	}
	
	/*
	 * isValidTemprature
	 * checks the validity of the temperature
	 */
	private boolean isValidTemprature(double tempC)
	{
		// Temperature should be between -45 °C and 65 °C
		return (tempC >= -45 && tempC <= 65);
	}
	
	/*
	 * isValidWindSpeed
	 * checks the validity of the wind speed
	 */
	private boolean isValidWindSpeed(double windSpeed)
	{
		// Wind speed should be greater than or equal to 0
		return (windSpeed >= 0);
	}
}
