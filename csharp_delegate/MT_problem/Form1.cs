using System;
using System.Threading;
using System.Windows.Forms;

namespace MT_problem
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Clock.Text = string.Format("{0}:{1:D2}:{2:D2}",
                DateTime.Now.Hour, DateTime.Now.Minute, DateTime.Now.Second);
        }

        private void TimerStart_Click(object sender, EventArgs e)
        {
            timer1.Start();
        }

        private void TimerStop_Click(object sender, EventArgs e)
        {
            timer1.Stop();
        }

        //funkcja, która zostanie wysłana w delegację
        void I_am_allowed_to_change_the_form(int x)
        {
            Clock.Text = "x = " + x++;
        }


        delegate void MyThreadDelegate(int x);
        volatile bool _continue = true;
        public void ThreadProc()
        {
            int x = 0;
            while (_continue)
            {
                //!!! nie wolno tutaj bezpośrednio majstrować przy okienku i kontrolkach
                //!!! Clock.Text = "x = " + x++; //wywali się z hukiem
                //!!!

                //...ale można zrobić to okrężną drogą:
                BeginInvoke
                    (
                    new MyThreadDelegate(I_am_allowed_to_change_the_form), //funkcja, której zlecamy zadanie do wykonania
                    new object[1] { x } //lista argumentów dla tej funkcji
                    );
                x++;
                Thread.Sleep(333);
             }
        }

        Thread thread;
        private void ThreadStart_Click(object sender, EventArgs e)
        {
            thread = new Thread(new ThreadStart(ThreadProc));
            thread.Start();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (thread != null)
            {
                _continue = false;
                thread.Join(); //czekaj, aż inny wątek zakończy działanie
             }
        }
    }
}
