#pragma once

namespace GraphicRedaktor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// Ãëàâíàÿ ôîğìà ãğàôè÷åñêîãî ğåäàêòîğà
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		// Êîíñòğóêòîğ ôîğìû
		MyForm(void)
		{
			InitializeComponent();

			// Ïğè çàïóñêå ïğîãğàììû àâòîìàòè÷åñêè ñîçäà¸òñÿ íîâûé ïóñòîé õîëñò
			ñîçäàòüToolStripMenuItem_Click(nullptr, nullptr);

			// Ïîäêëş÷åíèå îáğàáîò÷èêîâ êíîïîê âûáîğà èíñòğóìåíòà
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::btnLine_Click);
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::btnEllipse_Click);
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::btnRect_Click);

			// Ïîäêëş÷åíèå êíîïîê âûáîğà öâåòà
			this->btnPenColor->Click += gcnew System::EventHandler(this, &MyForm::öâåòToolStripMenuItem_Click);
			this->btnBrushColor->Click += gcnew System::EventHandler(this, &MyForm::öâåòToolStripMenuItem1_Click);

			// Íàñòğîéêà ñïèñêà âûáîğà òîëùèíû ëèíèè
			this->thicknessCombo->ComboBox->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->thicknessCombo->ComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;

			// Çàïîëíÿåì ñïèñîê òîëùèíû çíà÷åíèÿìè îò 1 äî 10
			for (int i = 1; i <= 10; i++)
				this->thicknessCombo->Items->Add(i);

			// Ïî óìîë÷àíèş âûáèğàåòñÿ ïåğâàÿ òîëùèíà
			this->thicknessCombo->SelectedIndex = 0;

			// Ïîäêëş÷àåì ñîáñòâåííûé ñïîñîá îòîáğàæåíèÿ ıëåìåíòîâ ñïèñêà òîëùèíû
			this->thicknessCombo->ComboBox->DrawItem +=
				gcnew System::Windows::Forms::DrawItemEventHandler(this, &MyForm::thicknessCombo_DrawItem);
		}

	private:
		// Êîîğäèíàòû ìûøè â ìîìåíò íàæàòèÿ êíîïêè
		static int startX, startY;

		// Êîîğäèíàòû ìûøè ïğè ïîñëåäíåì ïåğåìåùåíèè
		static int prevX, prevY;

		// Òåêóùèé èíñòğóìåíò:
		// 1 - ıëëèïñ
		// 2 - ïğÿìîóãîëüíèê
		// 3 - ëèíèÿ
		static int tool = 1;

		// Ôëàã íàëè÷èÿ íåñîõğàí¸ííûõ èçìåíåíèé
		static bool isChanged = false;

		// Îáëàñòü ïğåäïğîñìîòğà ôèãóğû
		static System::Drawing::Rectangle previewRect;

		// Îòğèñîâêà ëèíèè íóæíîé òîëùèíû â âûïàäàşùåì ñïèñêå
		void thicknessCombo_DrawItem(System::Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e)
		{
			if (e->Index < 0) return;

			e->DrawBackground();

			int thickness = safe_cast<int>(this->thicknessCombo->Items[e->Index]);
			System::Drawing::Pen^ p = gcnew System::Drawing::Pen(System::Drawing::Color::Black, (float)thickness);

			int y = e->Bounds.Top + e->Bounds.Height / 2;
			e->Graphics->DrawLine(p, e->Bounds.Left + 5, y, e->Bounds.Right - 5, y);

			delete p;
			e->DrawFocusRectangle();
		}

	protected:
		// Îñâîáîæäåíèå ğåñóğñîâ
		~MyForm()
		{
			if (components) delete components;
		}

	private:
		// Ãëàâíîå ìåíş
		System::Windows::Forms::MenuStrip^ menuStrip1;

		// Ìåíş "Ôàéë"
		System::Windows::Forms::ToolStripMenuItem^ ôàéëToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ ñîçäàòüToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ îòêğûòüToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ ñîõğàíèòüToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ ñîõğàíèòüÊàêToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;

		// Ìåíş "Êàğàíäàø"
		System::Windows::Forms::ToolStripMenuItem^ êàğàíäàøToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ öâåòToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ òîëùèíàToolStripMenuItem;
		System::Windows::Forms::ToolStripComboBox^ thicknessCombo;

		// Ìåíş "Êèñòü"
		System::Windows::Forms::ToolStripMenuItem^ êèñòüToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ öâåòToolStripMenuItem1;

		// Ïàíåëü èíñòğóìåíòîâ
		System::Windows::Forms::Panel^ panel1;

		// Êíîïêè âûáîğà ôèãóğû
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Button^ button2;
		System::Windows::Forms::Button^ button3;

		// Êíîïêè âûáîğà öâåòîâ
		System::Windows::Forms::Button^ btnPenColor;
		System::Windows::Forms::Button^ btnBrushColor;

		// Ôëàæîê çàëèâêè
		System::Windows::Forms::CheckBox^ chkFill;

		// Îáëàñòü ğèñîâàíèÿ
		System::Windows::Forms::PictureBox^ pictureBox1;

		// Äèàëîãè îòêğûòèÿ, ñîõğàíåíèÿ è âûáîğà öâåòà
		System::Windows::Forms::OpenFileDialog^ openFileDialog1;
		System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
		System::Windows::Forms::ColorDialog^ penColorDialog;
		System::Windows::Forms::ColorDialog^ brushColorDialog;

		// Âûáîğ èíñòğóìåíòà "Ëèíèÿ"
	private: System::Void btnLine_Click(System::Object^ sender, System::EventArgs^ e) { tool = 3; }

		   // Âûáîğ èíñòğóìåíòà "İëëèïñ"
	private: System::Void btnEllipse_Click(System::Object^ sender, System::EventArgs^ e) { tool = 1; }

		   // Âûáîğ èíñòğóìåíòà "Ïğÿìîóãîëüíèê"
	private: System::Void btnRect_Click(System::Object^ sender, System::EventArgs^ e) { tool = 2; }

		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->ôàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->ñîçäàòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->îòêğûòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->ñîõğàíèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->ñîõğàíèòüÊàêToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->êàğàíäàøToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->öâåòToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->òîëùèíàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->thicknessCombo = (gcnew System::Windows::Forms::ToolStripComboBox());
			   this->êèñòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->öâåòToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->btnBrushColor = (gcnew System::Windows::Forms::Button());
			   this->btnPenColor = (gcnew System::Windows::Forms::Button());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->chkFill = (gcnew System::Windows::Forms::CheckBox());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->penColorDialog = (gcnew System::Windows::Forms::ColorDialog());
			   this->brushColorDialog = (gcnew System::Windows::Forms::ColorDialog());
			   this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			   this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			   this->menuStrip1->SuspendLayout();
			   this->panel1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				   this->ôàéëToolStripMenuItem,
					   this->êàğàíäàøToolStripMenuItem, this->êèñòüToolStripMenuItem
			   });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(906, 24);
			   this->menuStrip1->TabIndex = 2;
			   // 
			   // ôàéëToolStripMenuItem
			   // 
			   this->ôàéëToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				   this->ñîçäàòüToolStripMenuItem,
					   this->îòêğûòüToolStripMenuItem, this->ñîõğàíèòüToolStripMenuItem, this->ñîõğàíèòüÊàêToolStripMenuItem, this->âûõîäToolStripMenuItem
			   });
			   this->ôàéëToolStripMenuItem->Name = L"ôàéëToolStripMenuItem";
			   this->ôàéëToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			   this->ôàéëToolStripMenuItem->Text = L"Ôàéë";
			   // 
			   // ñîçäàòüToolStripMenuItem
			   // 
			   this->ñîçäàòüToolStripMenuItem->Name = L"ñîçäàòüToolStripMenuItem";
			   this->ñîçäàòüToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			   this->ñîçäàòüToolStripMenuItem->Text = L"Ñîçäàòü";
			   this->ñîçäàòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ñîçäàòüToolStripMenuItem_Click);
			   // 
			   // îòêğûòüToolStripMenuItem
			   // 
			   this->îòêğûòüToolStripMenuItem->Name = L"îòêğûòüToolStripMenuItem";
			   this->îòêğûòüToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			   this->îòêğûòüToolStripMenuItem->Text = L"Îòêğûòü";
			   this->îòêğûòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::îòêğûòüToolStripMenuItem_Click);
			   // 
			   // ñîõğàíèòüToolStripMenuItem
			   // 
			   this->ñîõğàíèòüToolStripMenuItem->Name = L"ñîõğàíèòüToolStripMenuItem";
			   this->ñîõğàíèòüToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			   this->ñîõğàíèòüToolStripMenuItem->Text = L"Ñîõğàíèòü";
			   this->ñîõğàíèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ñîõğàíèòüToolStripMenuItem_Click);
			   // 
			   // ñîõğàíèòüÊàêToolStripMenuItem
			   // 
			   this->ñîõğàíèòüÊàêToolStripMenuItem->Name = L"ñîõğàíèòüÊàêToolStripMenuItem";
			   this->ñîõğàíèòüÊàêToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			   this->ñîõğàíèòüÊàêToolStripMenuItem->Text = L"Ñîõğàíèòü êàê";
			   this->ñîõğàíèòüÊàêToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ñîõğàíèòüÊàêToolStripMenuItem_Click);
			   // 
			   // âûõîäToolStripMenuItem
			   // 
			   this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			   this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			   this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			   this->âûõîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::âûõîäToolStripMenuItem_Click);
			   // 
			   // êàğàíäàøToolStripMenuItem
			   // 
			   this->êàğàíäàøToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->öâåòToolStripMenuItem,
					   this->òîëùèíàToolStripMenuItem
			   });
			   this->êàğàíäàøToolStripMenuItem->Name = L"êàğàíäàøToolStripMenuItem";
			   this->êàğàíäàøToolStripMenuItem->Size = System::Drawing::Size(75, 20);
			   this->êàğàíäàøToolStripMenuItem->Text = L"Êàğàíäàø";
			   // 
			   // öâåòToolStripMenuItem
			   // 
			   this->öâåòToolStripMenuItem->Name = L"öâåòToolStripMenuItem";
			   this->öâåòToolStripMenuItem->Size = System::Drawing::Size(125, 22);
			   this->öâåòToolStripMenuItem->Text = L"Öâåò";
			   this->öâåòToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::öâåòToolStripMenuItem_Click);
			   // 
			   // òîëùèíàToolStripMenuItem
			   // 
			   this->òîëùèíàToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->thicknessCombo });
			   this->òîëùèíàToolStripMenuItem->Name = L"òîëùèíàToolStripMenuItem";
			   this->òîëùèíàToolStripMenuItem->Size = System::Drawing::Size(125, 22);
			   this->òîëùèíàToolStripMenuItem->Text = L"Òîëùèíà";
			   // 
			   // thicknessCombo
			   // 
			   this->thicknessCombo->Name = L"thicknessCombo";
			   this->thicknessCombo->Size = System::Drawing::Size(121, 23);
			   // 
			   // êèñòüToolStripMenuItem
			   // 
			   this->êèñòüToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->öâåòToolStripMenuItem1 });
			   this->êèñòüToolStripMenuItem->Name = L"êèñòüToolStripMenuItem";
			   this->êèñòüToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			   this->êèñòüToolStripMenuItem->Text = L"Êèñòü";
			   // 
			   // öâåòToolStripMenuItem1
			   // 
			   this->öâåòToolStripMenuItem1->Name = L"öâåòToolStripMenuItem1";
			   this->öâåòToolStripMenuItem1->Size = System::Drawing::Size(100, 22);
			   this->öâåòToolStripMenuItem1->Text = L"Öâåò";
			   this->öâåòToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::öâåòToolStripMenuItem1_Click);
			   // 
			   // panel1
			   // 
			   this->panel1->Controls->Add(this->btnBrushColor);
			   this->panel1->Controls->Add(this->btnPenColor);
			   this->panel1->Controls->Add(this->button3);
			   this->panel1->Controls->Add(this->button2);
			   this->panel1->Controls->Add(this->button1);
			   this->panel1->Controls->Add(this->chkFill);
			   this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			   this->panel1->Location = System::Drawing::Point(0, 24);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(906, 74);
			   this->panel1->TabIndex = 1;
			   // 
			   // btnBrushColor
			   // 
			   this->btnBrushColor->BackColor = System::Drawing::Color::White;
			   this->btnBrushColor->Location = System::Drawing::Point(513, 10);
			   this->btnBrushColor->Name = L"btnBrushColor";
			   this->btnBrushColor->Size = System::Drawing::Size(132, 50);
			   this->btnBrushColor->TabIndex = 0;
			   this->btnBrushColor->Text = L"Öâåò êèñòè";
			   this->btnBrushColor->UseVisualStyleBackColor = false;
			   // 
			   // btnPenColor
			   // 
			   this->btnPenColor->BackColor = System::Drawing::Color::Black;
			   this->btnPenColor->ForeColor = System::Drawing::Color::White;
			   this->btnPenColor->Location = System::Drawing::Point(366, 10);
			   this->btnPenColor->Name = L"btnPenColor";
			   this->btnPenColor->Size = System::Drawing::Size(132, 50);
			   this->btnPenColor->TabIndex = 1;
			   this->btnPenColor->Text = L"Öâåò ïåğà";
			   this->btnPenColor->UseVisualStyleBackColor = false;
			   // 
			   // button3
			   // 
			   this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			   this->button3->Location = System::Drawing::Point(230, 10);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(130, 50);
			   this->button3->TabIndex = 2;
			   this->button3->Text = L"Ïğÿìîóãîëüíèê";
			   // 
			   // button2
			   // 
			   this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			   this->button2->Location = System::Drawing::Point(120, 10);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(100, 50);
			   this->button2->TabIndex = 3;
			   this->button2->Text = L"İëëèïñ";
			   // 
			   // button1
			   // 
			   this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			   this->button1->Location = System::Drawing::Point(5, 5);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(100, 50);
			   this->button1->TabIndex = 4;
			   this->button1->Text = L"Ëèíèÿ";
			   // 
			   // chkFill
			   // 
			   this->chkFill->Checked = true;
			   this->chkFill->CheckState = System::Windows::Forms::CheckState::Checked;
			   this->chkFill->Location = System::Drawing::Point(650, 25);
			   this->chkFill->Name = L"chkFill";
			   this->chkFill->Size = System::Drawing::Size(100, 24);
			   this->chkFill->TabIndex = 5;
			   this->chkFill->Text = L"Çàëèâêà";
			   this->chkFill->UseVisualStyleBackColor = true;
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackColor = System::Drawing::Color::White;
			   this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pictureBox1->Location = System::Drawing::Point(0, 98);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(906, 322);
			   this->pictureBox1->TabIndex = 0;
			   this->pictureBox1->TabStop = false;
			   this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			   this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			   this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			   this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			   // 
			   // openFileDialog1
			   // 
			   this->openFileDialog1->Filter = L"Image Files(*.BMP;*.JPG;*.PNG)|*.BMP;*.JPG;*.PNG";
			   // 
			   // saveFileDialog1
			   // 
			   this->saveFileDialog1->Filter = L"Image Files(*.BMP;*.JPG;*.PNG)|*.BMP;*.JPG;*.PNG";
			   // 
			   // MyForm
			   // 
			   this->ClientSize = System::Drawing::Size(906, 420);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->panel1);
			   this->Controls->Add(this->menuStrip1);
			   this->DoubleBuffered = true;
			   this->Name = L"MyForm";
			   this->Text = L"Ãğàôè÷åñêèé ğåäàêòîğ";
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   this->panel1->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

		   // Ñîçäàíèå íîâîãî ïóñòîãî èçîáğàæåíèÿ
	private: System::Void ñîçäàòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (pictureBox1->Image != nullptr)
			pictureBox1->Image->~Image();

		pictureBox1->Image = gcnew System::Drawing::Bitmap(pictureBox1->Width, pictureBox1->Height);

		System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(pictureBox1->Image);
		g->Clear(System::Drawing::Color::White);
		delete g;

		pictureBox1->Invalidate();
		this->Text = L"Áåçûìÿííûé";
		isChanged = false;
	}

		   // Îòêğûòèå èçîáğàæåíèÿ èç ôàéëà
	private: System::Void îòêğûòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (pictureBox1->Image != nullptr)
				pictureBox1->Image->~Image();

			pictureBox1->Image = System::Drawing::Image::FromFile(openFileDialog1->FileName);
			this->Text = openFileDialog1->FileName;
			isChanged = false;
			pictureBox1->Invalidate();
		}
	}

		   // Ñîõğàíåíèå èçîáğàæåíèÿ â òåêóùèé ôàéë
	private: System::Void ñîõğàíèòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (pictureBox1->Image == nullptr) return;

		if (this->Text == L"Áåçûìÿííûé") {
			ñîõğàíèòüÊàêToolStripMenuItem_Click(sender, e);
		}
		else {
			pictureBox1->Image->Save(this->Text);
			isChanged = false;
		}
	}

		   // Ñîõğàíåíèå èçîáğàæåíèÿ ïîä íîâûì èìåíåì
	private: System::Void ñîõğàíèòüÊàêToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (pictureBox1->Image != nullptr &&
			saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

			pictureBox1->Image->Save(saveFileDialog1->FileName);
			this->Text = saveFileDialog1->FileName;
			isChanged = false;
		}
	}

		   // Âûáîğ öâåòà ïåğà
	private: System::Void öâåòToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (penColorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			this->btnPenColor->BackColor = penColorDialog->Color;
			this->btnPenColor->ForeColor =
				(penColorDialog->Color.R < 120) ? System::Drawing::Color::White : System::Drawing::Color::Black;
		}
	}

		   // Âûáîğ öâåòà êèñòè
	private: System::Void öâåòToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (brushColorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			this->btnBrushColor->BackColor = brushColorDialog->Color;
			this->btnBrushColor->ForeColor =
				(brushColorDialog->Color.R < 120) ? System::Drawing::Color::White : System::Drawing::Color::Black;
		}
	}

		   // Âûõîä èç ïğèëîæåíèÿ
	private: System::Void âûõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

		   // Íàæàòèå ìûøè íà îáëàñòè ğèñîâàíèÿ
	private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (pictureBox1->Image == nullptr) return;

		startX = prevX = e->X;
		startY = prevY = e->Y;
	}

		   // Ïåğåìåùåíèå ìûøè ïğè íàæàòîé êíîïêå
	private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button != System::Windows::Forms::MouseButtons::Left) return;

		prevX = e->X;
		prevY = e->Y;

		previewRect = System::Drawing::Rectangle(
			Math::Min(startX, e->X),
			Math::Min(startY, e->Y),
			Math::Abs(e->X - startX),
			Math::Abs(e->Y - startY));

		pictureBox1->Invalidate();
	}

		   // Îòïóñêàíèå êíîïêè ìûøè è îêîí÷àòåëüíîå ğèñîâàíèå ôèãóğû
	private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (pictureBox1->Image == nullptr || e->Button != System::Windows::Forms::MouseButtons::Left) return;

		System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(pictureBox1->Image);
		float thickness = (float)safe_cast<int>(this->thicknessCombo->SelectedItem);
		System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(penColorDialog->Color, thickness);
		System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(brushColorDialog->Color);

		int nx = Math::Min(startX, e->X);
		int ny = Math::Min(startY, e->Y);
		int nw = Math::Abs(e->X - startX);
		int nh = Math::Abs(e->Y - startY);

		// İëëèïñ
		if (tool == 1) {
			if (this->chkFill->Checked)
				g->FillEllipse(brush, nx, ny, nw, nh);

			g->DrawEllipse(pen, nx, ny, nw, nh);
		}

		// Ïğÿìîóãîëüíèê
		if (tool == 2) {
			if (this->chkFill->Checked)
				g->FillRectangle(brush, nx, ny, nw, nh);

			g->DrawRectangle(pen, nx, ny, nw, nh);
		}

		// Ëèíèÿ
		if (tool == 3) {
			g->DrawLine(pen, startX, startY, e->X, e->Y);
		}

		delete pen;
		delete brush;
		delete g;

		previewRect = System::Drawing::Rectangle(0, 0, 0, 0);
		isChanged = true;
		pictureBox1->Invalidate();
	}

		   // Îòğèñîâêà ïğåäâàğèòåëüíîãî ïğîñìîòğà ôèãóğû
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (tool != 3 && previewRect.Width == 0 && previewRect.Height == 0) return;

		float thickness = (float)safe_cast<int>(this->thicknessCombo->SelectedItem);
		System::Drawing::Pen^ pPreview = gcnew System::Drawing::Pen(penColorDialog->Color, thickness);
		System::Drawing::SolidBrush^ bPreview =
			gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(100, brushColorDialog->Color));

		// İëëèïñ
		if (tool == 1) {
			if (this->chkFill->Checked)
				e->Graphics->FillEllipse(bPreview, previewRect);

			e->Graphics->DrawEllipse(pPreview, previewRect);
		}

		// Ïğÿìîóãîëüíèê
		if (tool == 2) {
			if (this->chkFill->Checked)
				e->Graphics->FillRectangle(bPreview, previewRect);

			e->Graphics->DrawRectangle(pPreview, previewRect);
		}

		// Ëèíèÿ
		if (tool == 3) {
			e->Graphics->DrawLine(pPreview, startX, startY, prevX, prevY);
		}

		delete pPreview;
		delete bPreview;
	}

		   // Îáğàáîò÷èê çàêğûòèÿ ôîğìû ñ çàïğîñîì íà ñîõğàíåíèå èçìåíåíèé
	private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (!isChanged) return;

		System::Windows::Forms::DialogResult dr = MessageBox::Show(
			L"Ñîõğàíèòü èçìåíåíèÿ â èçîáğàæåíèè?",
			L"Âûõîä èç ïğîãğàììû",
			MessageBoxButtons::YesNoCancel,
			MessageBoxIcon::Question);

		if (dr == System::Windows::Forms::DialogResult::Yes) {
			ñîõğàíèòüToolStripMenuItem_Click(sender, e);
		}
		else if (dr == System::Windows::Forms::DialogResult::Cancel) {
			e->Cancel = true;
		}
	}
	};
}