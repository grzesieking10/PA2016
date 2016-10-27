namespace MT_problem
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.TimerStart = new System.Windows.Forms.Button();
            this.TimerStop = new System.Windows.Forms.Button();
            this.Clock = new System.Windows.Forms.Label();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.ThreadStart = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // TimerStart
            // 
            this.TimerStart.Location = new System.Drawing.Point(12, 106);
            this.TimerStart.Name = "TimerStart";
            this.TimerStart.Size = new System.Drawing.Size(75, 23);
            this.TimerStart.TabIndex = 0;
            this.TimerStart.Text = "Start";
            this.TimerStart.UseVisualStyleBackColor = true;
            this.TimerStart.Click += new System.EventHandler(this.TimerStart_Click);
            // 
            // TimerStop
            // 
            this.TimerStop.Location = new System.Drawing.Point(93, 106);
            this.TimerStop.Name = "TimerStop";
            this.TimerStop.Size = new System.Drawing.Size(75, 23);
            this.TimerStop.TabIndex = 1;
            this.TimerStop.Text = "Stop";
            this.TimerStop.UseVisualStyleBackColor = true;
            this.TimerStop.Click += new System.EventHandler(this.TimerStop_Click);
            // 
            // Clock
            // 
            this.Clock.AutoSize = true;
            this.Clock.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.Clock.Font = new System.Drawing.Font("Consolas", 48F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.Clock.ForeColor = System.Drawing.Color.DodgerBlue;
            this.Clock.Location = new System.Drawing.Point(12, 9);
            this.Clock.Name = "Clock";
            this.Clock.Size = new System.Drawing.Size(314, 77);
            this.Clock.TabIndex = 2;
            this.Clock.Text = "00:00:00";
            // 
            // timer1
            // 
            this.timer1.Interval = 500;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // ThreadStart
            // 
            this.ThreadStart.Location = new System.Drawing.Point(251, 106);
            this.ThreadStart.Name = "ThreadStart";
            this.ThreadStart.Size = new System.Drawing.Size(75, 23);
            this.ThreadStart.TabIndex = 3;
            this.ThreadStart.Text = "Thread";
            this.ThreadStart.UseVisualStyleBackColor = true;
            this.ThreadStart.Click += new System.EventHandler(this.ThreadStart_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(342, 141);
            this.Controls.Add(this.ThreadStart);
            this.Controls.Add(this.Clock);
            this.Controls.Add(this.TimerStop);
            this.Controls.Add(this.TimerStart);
            this.Name = "Form1";
            this.Text = "Problem MT+Form";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button TimerStart;
        private System.Windows.Forms.Button TimerStop;
        private System.Windows.Forms.Label Clock;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button ThreadStart;
    }
}

