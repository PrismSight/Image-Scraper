#pragma once
#include <msclr\marshal_cppstd.h>
#include "ImgScraper.h"
#include "About.h"
#include <algorithm>

namespace ImageScraper {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RequestURL
	/// </summary>
	public ref class RequestURL : public System::Windows::Forms::Form
	{
	public:
		RequestURL(void)
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
		~RequestURL()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RequestURL::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(53, 6);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(419, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"https://";
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button1->BackColor = System::Drawing::SystemColors::Control;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(157, 229);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(175, 32);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Download Images";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &RequestURL::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"URL:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(13, 33);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(90, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Select Folder";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &RequestURL::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(109, 33);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(363, 20);
			this->textBox2->TabIndex = 4;
			// 
			// linkLabel1
			// 
			this->linkLabel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(437, 248);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(35, 13);
			this->linkLabel1->TabIndex = 5;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"About";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &RequestURL::linkLabel1_LinkClicked);
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Location = System::Drawing::Point(15, 61);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(457, 154);
			this->checkedListBox1->TabIndex = 6;
			// 
			// RequestURL
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(484, 266);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"RequestURL";
			this->Text = L"Image Scraper";
			this->Load += gcnew System::EventHandler(this, &RequestURL::RequestURL_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		FolderBrowserDialog^ FBD = gcnew FolderBrowserDialog();
		if (FBD->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			textBox2->Text = FBD->SelectedPath;
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		msclr::interop::marshal_context context;

		std::string URL = context.marshal_as<std::string>(textBox1->Text);
		std::string Directory = context.marshal_as<std::string>(textBox2->Text);
		if (Directory.length() > MAX_PATH)
		{
			MessageBox::Show("ERROR: Directory exceeds max characters!");
			return;
		}
		DWORD ftyp = GetFileAttributesA(Directory.c_str());
		if (ftyp == INVALID_FILE_ATTRIBUTES)
		{
			MessageBox::Show("ERROR: Bad Directory!");
			return;
		}
		std::vector<std::string> URLS = GetAllImgURLs(URL);
		if(URLS.size() <= 0)
		{
			MessageBox::Show("ERROR: No connection or no IMG tags");
			return;
		}

		
		URLS.erase(std::unique(URLS.begin(), URLS.end()), URLS.end()); // Remove duplicates

		this->checkedListBox1->Items->Clear();
		for (size_t i = 0; i < URLS.size(); i++)
		{
			// std::string FileName = URLS[i].substr(URLS[i].find_last_of("/")+1, URLS[i].length()-1);
			std::string FileName = URLS[i];
			String^ str3 = gcnew String(FileName.c_str());
			this->checkedListBox1->Items->Add(str3, true);
		}
		bool AllFilesDownloaded = true;
		for (size_t i = 0; i < URLS.size(); i++)
		{

			if (!DownloadImgFromURL(URLS[i], Directory))
			{
				AllFilesDownloaded = false;
			}
		}


		if(!AllFilesDownloaded)
			MessageBox::Show("ERROR: Could not download one or more files!");
		else
			MessageBox::Show("Succesfully downloaded all images!");
	}
private: System::Void RequestURL_Load(System::Object^ sender, System::EventArgs^ e) {
	TCHAR buffer[MAX_PATH] = { 0 };
	GetCurrentDirectory(MAX_PATH, buffer);
	System::String^ stringCurrentDir = gcnew System::String(buffer);
	textBox2->Text = stringCurrentDir;
}
private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	ImageScraper::About^ AboutUs = gcnew ImageScraper::About();
	AboutUs->ShowDialog();
}
};
}
