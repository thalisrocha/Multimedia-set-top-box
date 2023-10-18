/**
    * @file MainWindow.java
    * @author Thalis Rocha Pestana
    * @brief This class is used to create the main window of the application
    * @version 0.1
    * @date 2023-02-19
    * 
    */
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;

/**
 * @brief This class is used to create the main window of the application
 */
public class MainWindow extends JFrame {
    
    /**
     * @brief The text area for displaying output
     */
    private JTextArea textArea;

    /**
     * The action for playing a multimedia object
     */
    private Action addLine1Action;

    /**
     * The action for showing the multimedia variables
     */
    private Action addLine2Action;

    /**
     * The action for exiting the application
     */
    private Action exitAction;
    private static Client client;
    private static final long serialVersionUID = 1L;
    static final String DEFAULT_HOST = "localhost";
    static final int DEFAULT_PORT = 3331;
    private Socket sock;
    private BufferedReader input;
    private BufferedWriter output;

    public MainWindow() {
        // Set up the window
        setTitle("Main Window");
        setSize(400, 300);
        setLocationRelativeTo(null); // Center the window on the screen
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        // Set up the text area
        textArea = new JTextArea();
        textArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(textArea);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        getContentPane().add(scrollPane, BorderLayout.CENTER);
        
        JTextField addText = new JTextField(10);

        // Set up the actions
        addLine1Action = new AbstractAction("Play") {
            public void actionPerformed(ActionEvent e) {
                textArea.setText(null);
                String request = "play " + addText.getText();
                String response = client.send(request);
                textArea.append(response);
            }
        };
        addLine2Action = new AbstractAction("Show") {
            public void actionPerformed(ActionEvent e) {
                textArea.setText(null);
                String request = "show " + addText.getText();
                String response = client.send(request);
                textArea.append(response);
            }
        };
        exitAction = new AbstractAction("Exit") {
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        };
        add(addText, BorderLayout.SOUTH);
        
        // Set up the buttons
        JButton addButton1 = new JButton(addLine1Action);
        JButton addButton2 = new JButton(addLine2Action);
        JButton exitButton = new JButton(exitAction);
        JToolBar toolBar = new JToolBar();
        toolBar.add(addButton1);
        toolBar.add(addButton2);
        toolBar.add(exitButton);
        getContentPane().add(toolBar, BorderLayout.NORTH);
        
        // Set up the menu bar
        JMenuBar menuBar = new JMenuBar();  // Menu bar 
        JMenu fileMenu = new JMenu("Menu"); // Menu déroulant
        JMenuItem addLine1 = new JMenuItem(addLine1Action);
        JMenuItem addLine2 = new JMenuItem(addLine2Action);
        JMenuItem exitMenuItem = new JMenuItem(exitAction);
        fileMenu.add(addLine1);
        fileMenu.add(addLine2);
        fileMenu.add(exitMenuItem);
        menuBar.add(fileMenu);
        setJMenuBar(menuBar);
    }
    
    public static void main(String[] args) {
        MainWindow mainWindow = new MainWindow();
        mainWindow.setVisible(true);

        client = null;

        String host = DEFAULT_HOST;
        int port = DEFAULT_PORT;
        if (args.length >=1) host = args[0];
        if (args.length >=2) port = Integer.parseInt(args[1]);
    
        try {
            client = new Client(host, port);
        }
        catch (Exception e) {
            System.err.println("Client: Couldn't connect to "+host+":"+port);
            System.exit(1);
        }
    
        System.out.println("Client connected to "+host+":"+port);

        // pour lire depuis la console
        BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
    }
}
