
public class TestWeather {

	public static void main(String[] args) {
		Weather w1 = new Weather();
		Weather w2 = new Weather(-10, 20);
		System.out.println(w1.toString());
		System.out.println(w2.toString());
		w1.setTempC(-20);
		System.out.println(w1.toString());
		w1.setWindSpeed(70);
		System.out.println(w1.toString());
	}
}