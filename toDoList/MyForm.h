#pragma once

namespace toDoList {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ taskInp;
	protected:

	private: System::Windows::Forms::Button^ addTaskBtn;
	protected:

	protected:

	private: System::Windows::Forms::ListBox^ taskList;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->taskInp = (gcnew System::Windows::Forms::TextBox());
			this->addTaskBtn = (gcnew System::Windows::Forms::Button());
			this->taskList = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// taskInp
			// 
			this->taskInp->Location = System::Drawing::Point(34, 52);
			this->taskInp->Name = L"taskInp";
			this->taskInp->Size = System::Drawing::Size(260, 22);
			this->taskInp->TabIndex = 0;
			this->taskInp->Text = L"mnjjk";
			// 
			// addTaskBtn
			// 
			this->addTaskBtn->Location = System::Drawing::Point(348, 43);
			this->addTaskBtn->Name = L"addTaskBtn";
			this->addTaskBtn->Size = System::Drawing::Size(100, 40);
			this->addTaskBtn->TabIndex = 1;
			this->addTaskBtn->Text = L"Add Task";
			this->addTaskBtn->UseVisualStyleBackColor = true;
			this->addTaskBtn->Click += gcnew System::EventHandler(this, &MyForm::addTaskBtn_Click);
			// 
			// taskList
			// 
			this->taskList->FormattingEnabled = true;
			this->taskList->ItemHeight = 16;
			this->taskList->Location = System::Drawing::Point(34, 114);
			this->taskList->Name = L"taskList";
			this->taskList->Size = System::Drawing::Size(256, 260);
			this->taskList->TabIndex = 2;
			this->taskList->DoubleClick += gcnew System::EventHandler(this, &MyForm::list_item_double_click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(481, 422);
			this->Controls->Add(this->taskList);
			this->Controls->Add(this->addTaskBtn);
			this->Controls->Add(this->taskInp);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void addTaskBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ task = taskInp->Text;
		taskList->Items->Add(task);
		taskInp->Text = "";
	}
	private: System::Void list_item_double_click(System::Object^ sender, System::EventArgs^ e) {
		taskList->Items->Remove((taskList->SelectedItem)->ToString());
	}
	};
}
