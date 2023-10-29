#pragma once
#include <unordered_set>  
#include <msclr/marshal_cppstd.h>

namespace toDoList {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using System::Diagnostics::Debug;

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
	private: System::Windows::Forms::Label^ taskExistsLabel;
	private: System::Windows::Forms::Button^ Delete;
	private: System::Windows::Forms::Button^ Update;

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
			this->taskExistsLabel = (gcnew System::Windows::Forms::Label());
			this->Delete = (gcnew System::Windows::Forms::Button());
			this->Update = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// taskInp
			// 
			this->taskInp->Location = System::Drawing::Point(34, 52);
			this->taskInp->Name = L"taskInp";
			this->taskInp->Size = System::Drawing::Size(260, 22);
			this->taskInp->TabIndex = 0;
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
			this->taskList->Location = System::Drawing::Point(34, 113);
			this->taskList->Name = L"taskList";
			this->taskList->Size = System::Drawing::Size(256, 260);
			this->taskList->TabIndex = 2;
			this->taskList->DoubleClick += gcnew System::EventHandler(this, &MyForm::list_item_double_click);
			// 
			// taskExistsLabel
			// 
			this->taskExistsLabel->AutoSize = true;
			this->taskExistsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->taskExistsLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->taskExistsLabel->Location = System::Drawing::Point(91, 77);
			this->taskExistsLabel->Name = L"taskExistsLabel";
			this->taskExistsLabel->Size = System::Drawing::Size(130, 17);
			this->taskExistsLabel->TabIndex = 3;
			this->taskExistsLabel->Text = L"Task Already exists";
			// 
			// Delete
			// 
			this->Delete->Location = System::Drawing::Point(348, 113);
			this->Delete->Name = L"Delete";
			this->Delete->Size = System::Drawing::Size(100, 40);
			this->Delete->TabIndex = 3;
			this->Delete->Text = L"Delete";
			this->Delete->UseVisualStyleBackColor = true;
			this->Delete->Click += gcnew System::EventHandler(this, &MyForm::deleteItem);
			// 
			// Update
			// 
			this->Update->Location = System::Drawing::Point(348, 181);
			this->Update->Name = L"Update";
			this->Update->Size = System::Drawing::Size(100, 40);
			this->Update->TabIndex = 4;
			this->Update->Text = L"Update";
			this->Update->UseVisualStyleBackColor = true;
			this->Update->Click += gcnew System::EventHandler(this, &MyForm::updateItem);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(481, 422);
			this->Controls->Add(this->Update);
			this->Controls->Add(this->Delete);
			this->Controls->Add(this->taskList);
			this->Controls->Add(this->addTaskBtn);
			this->Controls->Add(this->taskInp);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"MyForm";
			this->Text = L"Taskify";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void addTaskBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ task = taskInp->Text->ToString();
		if (!task->Equals("")) {
			std::string nativeTask = msclr::interop::marshal_as<std::string>(task);
			std::unordered_set<std::string> set;

			for (int i = 0;i < taskList->Items->Count;i++) {
				String^ t = taskList->Items[i]->ToString();
				std::string nativeT = msclr::interop::marshal_as<std::string>(t);
				set.insert(nativeT.substr(3));
			}
			if (set.find(nativeTask) != set.end()) {
				this->Controls->Add(this->taskExistsLabel);
				taskInp->Text = "";
				wait(1000);
				this->Controls->Remove(this->taskExistsLabel);
			}
			else {
				taskList->Items->Add((taskList->Items->Count + 1) + ". " + task);
				taskInp->Text = "";
			}
		}
		
	}
	private: System::Void list_item_double_click(System::Object^ sender, System::EventArgs^ e) {
		String^ task = taskList->SelectedItem->ToString();
		int selectedItem = taskList->Items->IndexOf(task);
		Debug::WriteLine(selectedItem);
		taskList->Items->RemoveAt(selectedItem);
		taskList->Items->Insert(selectedItem,task + L"\u2713");
		wait(2000);
		taskList->Items->RemoveAt(selectedItem);
		for (int i = selectedItem;i < taskList->Items->Count;i++) {
			String^ t = taskList->Items[i]->ToString();
			taskList->Items->RemoveAt(i);
			taskList->Items->Insert(i, (i+1)+". "+t->Substring(3));
		}
	}

		   void wait(int n) {
			   DateTime startTime = DateTime::Now;
			   while ((DateTime::Now - startTime).TotalMilliseconds < n) {
				   Application::DoEvents();
			   }
		   }

		   private: System::Void deleteItem(System::Object^ sender, System::EventArgs^ e) {
			   String^ task = taskList->SelectedItem->ToString();
			   taskList->Items->Remove(task);
		   }

			private: System::Void updateItem(System::Object^ sender, System::EventArgs^ e) {
				String^ task = taskList->SelectedItem->ToString();
				String^ newTask = taskInp->Text->ToString();
				int i = taskList->Items->IndexOf(task);
				taskList->Items->RemoveAt(i);
				taskList->Items->Insert(i, (i + 1) + ". "+ newTask);
				taskInp->Text = "";
			}

	};
}
