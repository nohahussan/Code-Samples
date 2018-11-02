
//Assignment 5 Application: GuessGame.java
//Guess the number
import javax.swing.JFrame;

public class GuessGame
{
	public static void main( String args[] )
	{
		GuessGameFrame guessGameFrame = new GuessGameFrame();				// new frame for program
		guessGameFrame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );	// Window behavior when close button is clicked
		guessGameFrame.setSize( 300, 175 ); 								// set frame size
		guessGameFrame.setVisible( true ); 									// display frame
	} 																		// end main
} 																			// end class GuessGame