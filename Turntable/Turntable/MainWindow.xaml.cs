using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO.Ports;   

namespace Turntable
{
    /// <summary>
    /// MainWindow.xaml 的互動邏輯
    /// </summary>
    public partial class MainWindow : Window
    {

        SerialPort sp = new SerialPort();  

        public MainWindow()
        {
            
            InitializeComponent();

            sp.DataReceived += new SerialDataReceivedEventHandler(serialPort_DataReceived);

        }

        private void serialPort_DataReceived(object sender, SerialDataReceivedEventArgs e) {
            String data = sp.ReadLine();
            Console.Write("datareceived: " + data);
        }

        private void on_Click(object sender, RoutedEventArgs e)
        {
            sp.Write("1");
        }

        private void of_Click(object sender, RoutedEventArgs e)
        {
            sp.Write("0");
        }

        private void Connect_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                // String portName = comportno.Text;
                String portName = (string)cbbCOM.SelectedItem;
                sp.PortName = portName;
                sp.BaudRate = 9600;
                sp.Open();
                status.Text = "Connected";
            }
            catch (Exception)
            {

                MessageBox.Show("Please give a valid port number or check your connection");
            }
        }

        private void Disconnect_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                sp.Close();
                status.Text = "Disconnected";
            }
            catch (Exception)
            {

                MessageBox.Show("First Connect and then disconnect");
            }
        }

        private void Load_Click(object sender, RoutedEventArgs e)
        {
            string[] serialPorts = SerialPort.GetPortNames();
            cbbCOM.Items.Clear();

            foreach(string serialPort in serialPorts){
                cbbCOM.Items.Add(serialPort);

                if(cbbCOM.Items.Count > 0){
                    cbbCOM.SelectedIndex = 0;
                }
            }
        }     
    }
}
