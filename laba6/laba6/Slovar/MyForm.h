#pragma once

namespace Slovar {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	// Главная форма приложения "Частотный словарь"
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		// Конструктор формы
		MyForm(void)
		{
			InitializeComponent();

			// Устанавливаем первичный ключ таблицы вручную.
			// В качестве ключа используется столбец "word".
			// Это позволяет быстро находить слово в таблице методом Find().
			array<DataColumn^>^ key = gcnew array<DataColumn^>(1);
			key[0] = dataSet1->Tables["dictTable"]->Columns["word"];
			dataSet1->Tables["dictTable"]->PrimaryKey = key;
		}

	protected:
		/// <summary>
		/// Освобождение используемых ресурсов
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		// Главное меню программы
		System::Windows::Forms::MenuStrip^ menuStrip1;

		// Пункт меню "Файл"
		System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;

		// Подпункты меню "Файл"
		System::Windows::Forms::ToolStripMenuItem^ открытьToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;

		// Диалог открытия основного текстового файла
		System::Windows::Forms::OpenFileDialog^ openFileDialog1;

		// Набор данных и таблица словаря
		System::Data::DataSet^ dataSet1;
		System::Data::DataTable^ dictTable;

		// Столбцы таблицы словаря
		System::Data::DataColumn^ dataColumn1; // слово
		System::Data::DataColumn^ dataColumn2; // количество повторений

		// Таблица для отображения словаря на форме
		System::Windows::Forms::DataGridView^ dataGridView1;

		// Столбцы визуальной таблицы
		System::Windows::Forms::DataGridViewTextBoxColumn^ wordDataGridViewTextBoxColumn;
		System::Windows::Forms::DataGridViewTextBoxColumn^ countDataGridViewTextBoxColumn;

		// Элементы для поиска
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::Label^ label3;

		// Переключатель учета регистра
		System::Windows::Forms::CheckBox^ checkBoxCase;

		// Диалог выбора файла со стоп-словами
		System::Windows::Forms::OpenFileDialog^ openFileDialogStopWords;

		// Список стоп-слов
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::ListBox^ listBoxStopWords;

		// Кнопка для поиска самых длинных слов
		System::Windows::Forms::Button^ buttonLongestWords;

		// Метки статистики
		System::Windows::Forms::Label^ labelTotal;
		System::Windows::Forms::Label^ labelUnique;

	protected:
	private:
		/// <summary>
		/// Обязательная переменная конструктора
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Метод создания и настройки элементов интерфейса формы
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открытьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dataSet1 = (gcnew System::Data::DataSet());
			this->dictTable = (gcnew System::Data::DataTable());
			this->dataColumn1 = (gcnew System::Data::DataColumn());
			this->dataColumn2 = (gcnew System::Data::DataColumn());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->wordDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->countDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->checkBoxCase = (gcnew System::Windows::Forms::CheckBox());
			this->openFileDialogStopWords = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listBoxStopWords = (gcnew System::Windows::Forms::ListBox());
			this->buttonLongestWords = (gcnew System::Windows::Forms::Button());
			this->labelTotal = (gcnew System::Windows::Forms::Label());
			this->labelUnique = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dictTable))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();

			// 
			// menuStrip1
			// 
			// Главное меню формы
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^ >(1) {
				this->файлToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(822, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";

			// 
			// файлToolStripMenuItem
			// 
			// Меню "Файл"
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^ >(2) {
				this->открытьToolStripMenuItem,
					this->выходToolStripMenuItem
			});
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(59, 24);
			this->файлToolStripMenuItem->Text = L"Файл";

			// 
			// открытьToolStripMenuItem
			// 
			// Команда открытия текстового файла
			this->открытьToolStripMenuItem->Name = L"открытьToolStripMenuItem";
			this->открытьToolStripMenuItem->Size = System::Drawing::Size(150, 26);
			this->открытьToolStripMenuItem->Text = L"Открыть";
			this->открытьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::открытьToolStripMenuItem_Click);

			// 
			// выходToolStripMenuItem
			// 
			// Команда выхода из программы
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(150, 26);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::выходToolStripMenuItem_Click);

			// 
			// openFileDialog1
			// 
			// Диалог выбора текстового файла
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"Text Files(*.TXT)|*.TXT";

			// 
			// dataSet1
			// 
			// Набор данных, в котором хранится словарь
			this->dataSet1->DataSetName = L"NewDataSet";
			this->dataSet1->Tables->AddRange(gcnew cli::array< System::Data::DataTable^ >(1) { this->dictTable });

			// 
			// dictTable
			// 
			// Таблица словаря
			this->dictTable->Columns->AddRange(gcnew cli::array< System::Data::DataColumn^ >(2) {
				this->dataColumn1, this->dataColumn2
			});
			this->dictTable->TableName = L"dictTable";

			// 
			// dataColumn1
			// 
			// Столбец для хранения слова
			this->dataColumn1->AllowDBNull = false;
			this->dataColumn1->ColumnName = L"word";

			// 
			// dataColumn2
			// 
			// Столбец для хранения количества повторений
			this->dataColumn2->AllowDBNull = false;
			this->dataColumn2->ColumnName = L"count";
			this->dataColumn2->DataType = System::Int32::typeid;

			// 
			// dataGridView1
			// 
			// Таблица для отображения словаря на форме
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AutoGenerateColumns = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^ >(2) {
				this->wordDataGridViewTextBoxColumn,
					this->countDataGridViewTextBoxColumn
			});
			this->dataGridView1->DataMember = L"dictTable";
			this->dataGridView1->DataSource = this->dataSet1;
			this->dataGridView1->Location = System::Drawing::Point(0, 28);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(350, 150);
			this->dataGridView1->TabIndex = 1;

			// 
			// wordDataGridViewTextBoxColumn
			// 
			// Столбец отображения слова
			this->wordDataGridViewTextBoxColumn->DataPropertyName = L"word";
			this->wordDataGridViewTextBoxColumn->HeaderText = L"Слово";
			this->wordDataGridViewTextBoxColumn->MinimumWidth = 6;
			this->wordDataGridViewTextBoxColumn->Name = L"wordDataGridViewTextBoxColumn";
			this->wordDataGridViewTextBoxColumn->ReadOnly = true;
			this->wordDataGridViewTextBoxColumn->Width = 125;

			// 
			// countDataGridViewTextBoxColumn
			// 
			// Столбец отображения количества повторений
			this->countDataGridViewTextBoxColumn->DataPropertyName = L"count";
			this->countDataGridViewTextBoxColumn->HeaderText = L"Количество";
			this->countDataGridViewTextBoxColumn->MinimumWidth = 6;
			this->countDataGridViewTextBoxColumn->Name = L"countDataGridViewTextBoxColumn";
			this->countDataGridViewTextBoxColumn->ReadOnly = true;
			this->countDataGridViewTextBoxColumn->Width = 125;

			// 
			// label1
			// 
			// Подпись к полю поиска
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(356, 100);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Поиск буквы";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);

			// 
			// textBox1
			// 
			// Поле ввода буквы или строки для поиска
			this->textBox1->Location = System::Drawing::Point(452, 100);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);

			// 
			// label3
			// 
			// Дополнительная метка (в данной версии не используется)
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(558, 106);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 16);
			this->label3->TabIndex = 4;

			// 
			// checkBoxCase
			// 
			// Переключатель учета регистра
			this->checkBoxCase->AutoSize = true;
			this->checkBoxCase->Location = System::Drawing::Point(359, 136);
			this->checkBoxCase->Name = L"checkBoxCase";
			this->checkBoxCase->Size = System::Drawing::Size(155, 20);
			this->checkBoxCase->TabIndex = 6;
			this->checkBoxCase->Text = L"Учитывать регистр";
			this->checkBoxCase->UseVisualStyleBackColor = true;
			this->checkBoxCase->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxCase_CheckedChanged);

			// 
			// openFileDialogStopWords
			// 
			// Диалог выбора файла со стоп-словами
			this->openFileDialogStopWords->FileName = L"openFileDialog2";
			this->openFileDialogStopWords->Title = L"Выберите файл стоп-слов";

			// 
			// label2
			// 
			// Подпись к списку стоп-слов
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(359, 186);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 16);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Стоп слова:";

			// 
			// listBoxStopWords
			// 
			// Список загруженных стоп-слов
			this->listBoxStopWords->FormattingEnabled = true;
			this->listBoxStopWords->ItemHeight = 16;
			this->listBoxStopWords->Location = System::Drawing::Point(362, 218);
			this->listBoxStopWords->Name = L"listBoxStopWords";
			this->listBoxStopWords->Size = System::Drawing::Size(120, 84);
			this->listBoxStopWords->TabIndex = 8;

			// 
			// buttonLongestWords
			// 
			// Кнопка поиска самых длинных слов
			this->buttonLongestWords->Location = System::Drawing::Point(13, 278);
			this->buttonLongestWords->Name = L"buttonLongestWords";
			this->buttonLongestWords->Size = System::Drawing::Size(179, 23);
			this->buttonLongestWords->TabIndex = 9;
			this->buttonLongestWords->Text = L"Самые длинные слова";
			this->buttonLongestWords->UseVisualStyleBackColor = true;
			this->buttonLongestWords->Click += gcnew System::EventHandler(this, &MyForm::buttonLongestWords_Click);

			// 
			// labelTotal
			// 
			// Метка общего количества совпадений
			this->labelTotal->AutoSize = true;
			this->labelTotal->Location = System::Drawing::Point(564, 103);
			this->labelTotal->Name = L"labelTotal";
			this->labelTotal->Size = System::Drawing::Size(130, 16);
			this->labelTotal->TabIndex = 10;
			this->labelTotal->Text = L"Всего совпадений:";

			// 
			// labelUnique
			// 
			// Метка количества различных слов
			this->labelUnique->AutoSize = true;
			this->labelUnique->Location = System::Drawing::Point(564, 137);
			this->labelUnique->Name = L"labelUnique";
			this->labelUnique->Size = System::Drawing::Size(116, 16);
			this->labelUnique->TabIndex = 11;
			this->labelUnique->Text = L"Различных слов:";

			// 
			// MyForm
			// 
			// Настройка формы
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(822, 436);
			this->Controls->Add(this->labelUnique);
			this->Controls->Add(this->labelTotal);
			this->Controls->Add(this->buttonLongestWords);
			this->Controls->Add(this->listBoxStopWords);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->checkBoxCase);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Словарь";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dictTable))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}

	private:
		// Обработчик меню "Открыть"
		// Загружает стоп-слова (если нужно), затем анализирует основной текстовый файл
		System::Void открытьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

			// Список стоп-слов
			Collections::Generic::List<String^>^ stopWords = gcnew Collections::Generic::List<String^>();

			// Спрашиваем пользователя, нужен ли файл со стоп-словами
			System::Windows::Forms::DialogResult result = MessageBox::Show(
				"Нужно выбрать файл со стоп-словами?",
				"Настройка фильтра",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Question
			);

			// Если пользователь выбрал загрузку стоп-слов
			if (result == System::Windows::Forms::DialogResult::Yes) {
				listBoxStopWords->Items->Clear();

				if (openFileDialogStopWords->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

					// Читаем стоп-слова из файла построчно
					array<String^>^ lines = System::IO::File::ReadAllLines(openFileDialogStopWords->FileName);

					for each (String ^ line in lines) {
						if (!String::IsNullOrWhiteSpace(line)) {
							String^ sWord = line->Trim()->ToLower();
							stopWords->Add(sWord);
							listBoxStopWords->Items->Add(sWord);
						}
					}

					MessageBox::Show("Стоп-слова загружены. Теперь выберите основной текстовый файл.", "Информация");
				}
			}
			else {
				// Если стоп-слова не используются, очищаем список
				listBoxStopWords->Items->Clear();
				MessageBox::Show("Фильтрация отключена. Выберите основной текстовый файл.", "Информация");
			}

			// Выбор основного текстового файла
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				System::IO::Stream^ myStream = openFileDialog1->OpenFile();

				if (myStream != nullptr) {
					// Считываем весь файл в строку
					System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(myStream);
					String^ s = sr->ReadToEnd();
					sr->Close();
					myStream->Close();

					// Устанавливаем режим учета регистра для таблицы
					dataSet1->Tables["dictTable"]->CaseSensitive = checkBoxCase->Checked;

					// Очищаем словарь от старых данных
					dataSet1->Tables["dictTable"]->Clear();

					int i = 0;

					// Разбор текста на слова
					while (i < s->Length) {

						// Поиск начала слова
						while (i < s->Length && !Char::IsLetter(s, i)) i++;
						if (i >= s->Length) break;

						// Поиск конца слова
						int j = i + 1;
						while (j < s->Length && Char::IsLetter(s, j)) j++;

						// Получаем слово
						String^ word = s->Substring(i, j - i);

						// Если слово входит в список стоп-слов, пропускаем его
						if (stopWords->Contains(word->ToLower())) {
							i = j;
							continue;
						}

						// Поиск слова в таблице словаря
						DataRow^ dr = dataSet1->Tables["dictTable"]->Rows->Find(word);

						if (dr != nullptr) {
							// Если слово найдено, увеличиваем счетчик
							dr["count"] = Convert::ToInt32(dr["count"]) + 1;
						}
						else {
							// Если слова нет, добавляем новую строку
							dr = dataSet1->Tables["dictTable"]->NewRow();
							dr["word"] = word;
							dr["count"] = 1;
							dataSet1->Tables["dictTable"]->Rows->Add(dr);
						}

						i = j;
					}

					// Сразу сортируем таблицу по слову в алфавитном порядке
					if (dataGridView1->Columns->Count > 0) {
						dataGridView1->Sort(dataGridView1->Columns[0], System::ComponentModel::ListSortDirection::Ascending);
					}

					// После загрузки обновляем статистику
					textBox1_TextChanged(nullptr, nullptr);
				}
				else {
					MessageBox::Show("Не удалось открыть файл текста.");
				}
			}
		}

		// Обработчик выхода из программы
		System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			Application::Exit();
		}

		// Обработчик изменения текста в поле поиска
		// Подсчитывает:
		// 1. Общее число совпадений
		// 2. Число различных слов, содержащих введённую строку
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(textBox1->Text)) {
			labelTotal->Text = "Всего совпадений: 0";
			labelUnique->Text = "Различных слов: 0";
			return;
		}

		int total = 0;
		int unique = 0;
		String^ find = textBox1->Text;
		DataTable^ table = dataSet1->Tables["dictTable"];

		for (int i = 0; i < table->Rows->Count; i++) {
			String^ word = table->Rows[i]->default["word"]->ToString();
			bool isMatch = false;

			// Поиск с учетом или без учета регистра
			if (checkBoxCase->Checked) {
				if (word->Contains(find)) isMatch = true;
			}
			else {
				if (word->ToLower()->Contains(find->ToLower())) isMatch = true;
			}

			if (isMatch) {
				total += Convert::ToInt32(table->Rows[i]->default["count"]);
				unique++;
			}
		}

		// Вывод статистики
		labelTotal->Text = "Всего совпадений: " + total.ToString();
		labelUnique->Text = "Различных слов: " + unique.ToString();
	}

#pragma endregion

		   // Пустой обработчик клика по label1
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

		   // Обработчик переключения режима учета регистра
		   // Просто пересчитывает статистику
	private: System::Void checkBoxCase_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		textBox1_TextChanged(nullptr, nullptr);
	}

		   // Обработчик загрузки формы
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

		   // Обработчик кнопки "Самые длинные слова"
		   // Находит максимальную длину слова и выводит до 3 самых длинных слов
	private: System::Void buttonLongestWords_Click(System::Object^ sender, System::EventArgs^ e) {
		DataTable^ table = dataSet1->Tables["dictTable"];

		if (table->Rows->Count == 0) {
			MessageBox::Show("Словарь пуст!");
			return;
		}

		int maxLength = 0;

		// Находим максимальную длину слова
		for (int i = 0; i < table->Rows->Count; i++) {
			String^ word = table->Rows[i]->default["word"]->ToString();
			if (word->Length > maxLength) {
				maxLength = word->Length;
			}
		}

		// Сохраняем найденные слова максимальной длины
		Collections::Generic::List<String^>^ foundWords = gcnew Collections::Generic::List<String^>();

		for (int i = 0; i < table->Rows->Count; i++) {
			String^ word = table->Rows[i]->default["word"]->ToString();

			if (word->Length == maxLength) {
				foundWords->Add(word);
			}

			// Ограничиваем вывод тремя словами
			if (foundWords->Count == 3) {
				break;
			}
		}

		// Формируем сообщение
		String^ message = "Самые длинные слова (длина " + maxLength.ToString() + "):\n";

		for (int k = 0; k < foundWords->Count; k++) {
			message += (k + 1).ToString() + ". " + foundWords[k] + "\n";
		}

		MessageBox::Show(message, "Результат поиска");
	}

		   // Пустой обработчик labelUnique
	private: System::Void labelCountUnique_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
};