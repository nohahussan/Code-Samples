// Template Assignment 5: GuessGameFrame.java
// Guess the number

import java.awt.FlowLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.util.Random;

import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JButton;

@SuppressWarnings("serial")
public class GuessGameFrame extends JFrame
{
	private static Random generator = new Random();
	private int number; 								// number chosen by application
	private JTextField guessInputJTextField; 			// for guessing
	private JLabel prompt1JLabel; 						// first prompt to user
	private JLabel prompt2JLabel; 						// second prompt to user
	private JLabel messageJLabel; 						// displays message of game status
	private JButton newGameJButton; 					// creates new game

	// set up GUI and initialize values
	public GuessGameFrame()
	{
		/* calls the superclass constructor and 
		 * set the title of this application to "Guessing Game"
		 */
		super("Guessing Game");

		prompt1JLabel = new JLabel(
				"I have a number between 1 and 1000." ); 		// describe game
		prompt2JLabel = new JLabel(
				"Can you guess my number? Enter your Guess:" ); // prompt user

		guessInputJTextField = new JTextField( 5 ); 			// to enter guesses
		guessInputJTextField.addActionListener( new GuessHandler( ) );
		messageJLabel = new JLabel( "Guess result appears here." );

		//create the "New Game" button
		newGameJButton = new JButton("New Game");

		// add action listener, by creating an anonymous inner class
		newGameJButton.addActionListener( new ActionListener() 	// anonymous inner class
		{
			public void actionPerformed( ActionEvent e )
			{
				/* reset the application to an appropriate state
				 * to start a new game. Set the JTextFields to their initial text,
				 * call method startTheGame and repaint the GuessGame JFrame
				 */
				messageJLabel.setText("Guess result appears here.");
				guessInputJTextField.setText("");
				guessInputJTextField.setEditable(true);
				guessInputJTextField.grabFocus();
				startTheGame();
				repaint();

			} 													// end method actionPerformed
		} 														// end anonymous inner class
		); 														// end call to addActionListener

		/* set the layout of the container to a Flowlayout,
		 * then add all the GUI components to the container
		 */
		setLayout(new FlowLayout());
		add(prompt1JLabel);
		add(prompt2JLabel);
		add(guessInputJTextField);
		add(messageJLabel);
		add(newGameJButton);
		startTheGame(); 										// start new game
	} 															// end GuessGameFrame constructor

	// choose a new random number
	public void startTheGame()
	{
		/* set instance variable number 
		 * to a random number between 1 and 1000
		 */  
		number = generator.nextInt(1000) + 1;					//Generate a number between 0 and 999, add one -> (1-1000)
	} 															// end method startTheGame

	// response to new guess
	public void response( int guess )
	{
		if ( guess > number )									// guess is too high
		{
			messageJLabel.setText( "Too High. Try a lower number." );
		}
		else if ( guess < number ) 								// guess is too low
		{
			messageJLabel.setText( "Too Low. Try a higher number." );
		}
		else 													// guess is correct
		{
			messageJLabel.setText( "Correct!" );
			guessInputJTextField.setEditable(false); 			// Set the guessInputJTextField to un-editable
		}

		repaint();
	} 															// end method response

	// inner class acts on user input
	class GuessHandler implements ActionListener
	{
		public void actionPerformed( ActionEvent e )
		{
			try
			{
				int userInput = Integer.parseInt(guessInputJTextField.getText()); 	// obtain the guess, convert it to an int
				response(userInput);												// pass that value to the response method
			}
			catch(NumberFormatException exception)									// if user enters a non integer value
			{
				guessInputJTextField.setText("");
				messageJLabel.setText( "Please enter an integer vlaue between 1-1000" );
			}
		} 																		// end method actionPerformed
	} 																			// end inner class GuessHandler
} 																				// end class GuessGameFrame

