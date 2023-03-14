#include <map>
#include <string>
#include <iostream>
#include <vector>
#include<unordered_map>
#include "PRNG.h"
#include <fstream>

#include <random>
#include <iomanip>
#include <array>
#include <map>

//#include "PRNG.h"
#pragma once

namespace CppCLRWinformsProjekt {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Windows::Forms;
    using namespace System::Collections;
    using namespace System::Collections::Generic;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Windows::Forms::DataVisualization::Charting;


    enum RandomType
    {
        uniformDistribution = 0,
        uniformDistributionInterval = 1,
        xorShift128 = 2,
        standartUniformRandom = 3,
        standartRandom = 4,
        triangle = 5
    };
    enum GraphicType
    {
        randomValueCurveFromTheAttemptNumber = 0,
        randomValueMatchDiagram = 1,
        probabilityDistributeDiagram = 2
    };

    /// <summary>
    /// Summary for MyForm
    /// </summary>
        public ref class MyForm : public System::Windows::Forms::Form
        {
        public:
            MyForm(void) {
                InitializeComponent();
            }
        protected:
            /// <summary>
            /// Clean up any resources being used.
            /// </summary>
            ~MyForm() {
                if (components)
                {
                    delete components;
                }
            }
        protected:

        private: System::Windows::Forms::TextBox^ NId;
        private: System::Windows::Forms::TextBox^ BId;
        private: System::Windows::Forms::TextBox^ AId;

        private: System::Windows::Forms::Label^ BLabel;
        private: System::Windows::Forms::Label^ ALabel;
        private: System::Windows::Forms::Label^ NLabel;

        private: System::Windows::Forms::Button^ renderBtn;

        private: System::Windows::Forms::ComboBox^ graphic;
        private: System::Windows::Forms::ComboBox^ method;

        private: System::Windows::Forms::SplitContainer^ layout;

        private: System::Windows::Forms::DataVisualization::Charting::Chart^ graphicSpace;

        protected:

        private:
            System::ComponentModel::IContainer^ components;
            List<KeyValuePair<String^, int>>^ methods;
        private: System::Windows::Forms::Label^ label1;
        private: System::Windows::Forms::TextBox^ textBox1;
        private: System::Windows::Forms::DataGridView^ dataGridView1;
        private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;






               List<KeyValuePair<String^, int>>^ graphics;

    #pragma region Windows Form Designer generated code
            /// <summary>
            /// Required method for Designer support - do not modify
            /// the contents of this method with the code editor.
            /// </summary>
            void InitializeComponent(void)
            {
                PairFormComboBoxInit();
                System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
                System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
                this->layout = (gcnew System::Windows::Forms::SplitContainer());
                this->graphicSpace = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
                this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
                this->label1 = (gcnew System::Windows::Forms::Label());
                this->textBox1 = (gcnew System::Windows::Forms::TextBox());
                this->BLabel = (gcnew System::Windows::Forms::Label());
                this->BId = (gcnew System::Windows::Forms::TextBox());
                this->ALabel = (gcnew System::Windows::Forms::Label());
                this->AId = (gcnew System::Windows::Forms::TextBox());
                this->graphic = (gcnew System::Windows::Forms::ComboBox());
                this->method = (gcnew System::Windows::Forms::ComboBox());
                this->NLabel = (gcnew System::Windows::Forms::Label());
                this->NId = (gcnew System::Windows::Forms::TextBox());
                this->renderBtn = (gcnew System::Windows::Forms::Button());
                this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
                (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->layout))->BeginInit();
                this->layout->Panel1->SuspendLayout();
                this->layout->Panel2->SuspendLayout();
                this->layout->SuspendLayout();
                (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->graphicSpace))->BeginInit();
                (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
                this->SuspendLayout();
                // 
                // layout
                // 
                this->layout->Location = System::Drawing::Point(9, 10);
                this->layout->Margin = System::Windows::Forms::Padding(2);
                this->layout->Name = L"layout";
                // 
                // layout.Panel1
                // 
                this->layout->Panel1->Controls->Add(this->graphicSpace);
                this->layout->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::splitContainer1_Panel1_Paint);
                // 
                // layout.Panel2
                // 
                this->layout->Panel2->Controls->Add(this->dataGridView1);
                this->layout->Panel2->Controls->Add(this->label1);
                this->layout->Panel2->Controls->Add(this->textBox1);
                this->layout->Panel2->Controls->Add(this->BLabel);
                this->layout->Panel2->Controls->Add(this->BId);
                this->layout->Panel2->Controls->Add(this->ALabel);
                this->layout->Panel2->Controls->Add(this->AId);
                this->layout->Panel2->Controls->Add(this->graphic);
                this->layout->Panel2->Controls->Add(this->method);
                this->layout->Panel2->Controls->Add(this->NLabel);
                this->layout->Panel2->Controls->Add(this->NId);
                this->layout->Panel2->Controls->Add(this->renderBtn);
                this->layout->Size = System::Drawing::Size(1540, 817);
                this->layout->SplitterDistance = 1112;
                this->layout->SplitterWidth = 3;
                this->layout->TabIndex = 1;
                // 
                // graphicSpace
                // 
                chartArea2->Name = L"ChartArea1";
                this->graphicSpace->ChartAreas->Add(chartArea2);
                this->graphicSpace->Location = System::Drawing::Point(3, 3);
                this->graphicSpace->Name = L"graphicSpace";
                series2->ChartArea = L"ChartArea1";
                series2->Name = L"Series1";
                this->graphicSpace->Series->Add(series2);
                this->graphicSpace->Size = System::Drawing::Size(1106, 811);
                this->graphicSpace->TabIndex = 0;
                this->graphicSpace->Text = L"chart1";
                this->graphicSpace->Click += gcnew System::EventHandler(this, &MyForm::graphicSpace_Click);
                // 
                // dataGridView1
                // 
                this->dataGridView1->AllowUserToDeleteRows = false;
                this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
                this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Column1 });
                this->dataGridView1->Location = System::Drawing::Point(106, 243);
                this->dataGridView1->Name = L"dataGridView1";
                this->dataGridView1->ReadOnly = true;
                this->dataGridView1->Size = System::Drawing::Size(241, 571);
                this->dataGridView1->TabIndex = 12;
                this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
                // 
                // label1
                // 
                this->label1->AutoSize = true;
                this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                    static_cast<System::Byte>(204)));
                this->label1->Location = System::Drawing::Point(104, 75);
                this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
                this->label1->Name = L"label1";
                this->label1->Size = System::Drawing::Size(29, 17);
                this->label1->TabIndex = 11;
                this->label1->Text = L"C:=";
                // 
                // textBox1
                // 
                this->textBox1->Location = System::Drawing::Point(136, 75);
                this->textBox1->Margin = System::Windows::Forms::Padding(2);
                this->textBox1->Name = L"textBox1";
                this->textBox1->Size = System::Drawing::Size(211, 20);
                this->textBox1->TabIndex = 10;
                // 
                // BLabel
                // 
                this->BLabel->AutoSize = true;
                this->BLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                    static_cast<System::Byte>(204)));
                this->BLabel->Location = System::Drawing::Point(103, 51);
                this->BLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
                this->BLabel->Name = L"BLabel";
                this->BLabel->Size = System::Drawing::Size(29, 17);
                this->BLabel->TabIndex = 9;
                this->BLabel->Text = L"B:=";
                // 
                // BId
                // 
                this->BId->Location = System::Drawing::Point(135, 51);
                this->BId->Margin = System::Windows::Forms::Padding(2);
                this->BId->Name = L"BId";
                this->BId->Size = System::Drawing::Size(211, 20);
                this->BId->TabIndex = 8;
                // 
                // ALabel
                // 
                this->ALabel->AutoSize = true;
                this->ALabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                    static_cast<System::Byte>(204)));
                this->ALabel->Location = System::Drawing::Point(103, 28);
                this->ALabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
                this->ALabel->Name = L"ALabel";
                this->ALabel->Size = System::Drawing::Size(29, 17);
                this->ALabel->TabIndex = 7;
                this->ALabel->Text = L"A:=";
                // 
                // AId
                // 
                this->AId->Location = System::Drawing::Point(135, 28);
                this->AId->Margin = System::Windows::Forms::Padding(2);
                this->AId->Name = L"AId";
                this->AId->Size = System::Drawing::Size(211, 20);
                this->AId->TabIndex = 6;
                // 
                // graphic
                // 
                this->graphic->DisplayMember = L"Key";
                this->graphic->FormattingEnabled = true;
                this->graphic->Location = System::Drawing::Point(106, 128);
                this->graphic->Margin = System::Windows::Forms::Padding(2);
                this->graphic->Name = L"graphic";
                this->graphic->Size = System::Drawing::Size(240, 21);
                this->graphic->TabIndex = 5;
                this->graphic->ValueMember = L"Value";
                this->graphic->DataSource = graphics;
                // 
                // method
                // 
                this->method->DisplayMember = L"Key";
                this->method->FormattingEnabled = true;
                this->method->Location = System::Drawing::Point(106, 100);
                this->method->Margin = System::Windows::Forms::Padding(2);
                this->method->Name = L"method";
                this->method->Size = System::Drawing::Size(240, 21);
                this->method->TabIndex = 4;
                this->method->ValueMember = L"Value";
                this->method->DataSource = methods;
                // 
                // NLabel
                // 
                this->NLabel->AutoSize = true;
                this->NLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                    static_cast<System::Byte>(204)));
                this->NLabel->Location = System::Drawing::Point(103, 6);
                this->NLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
                this->NLabel->Name = L"NLabel";
                this->NLabel->Size = System::Drawing::Size(30, 17);
                this->NLabel->TabIndex = 3;
                this->NLabel->Text = L"N:=";
                // 
                // NId
                // 
                this->NId->Location = System::Drawing::Point(135, 6);
                this->NId->Margin = System::Windows::Forms::Padding(2);
                this->NId->Name = L"NId";
                this->NId->Size = System::Drawing::Size(211, 20);
                this->NId->TabIndex = 2;
                // 
                // renderBtn
                // 
                this->renderBtn->Location = System::Drawing::Point(106, 157);
                this->renderBtn->Margin = System::Windows::Forms::Padding(2);
                this->renderBtn->Name = L"renderBtn";
                this->renderBtn->Size = System::Drawing::Size(240, 19);
                this->renderBtn->TabIndex = 1;
                this->renderBtn->Text = L"Render";
                this->renderBtn->UseVisualStyleBackColor = true;
                this->renderBtn->Click += gcnew System::EventHandler(this, &MyForm::renderBtn_Click);
                // 
                // Column1
                // 
                this->Column1->HeaderText = L"Случайное число";
                this->Column1->Name = L"Column1";
                this->Column1->ReadOnly = true;
                this->Column1->Width = 197;
                // 
                // MyForm
                // 
                this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
                this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
                this->ClientSize = System::Drawing::Size(1560, 838);
                this->Controls->Add(this->layout);
                this->Name = L"MyForm";
                this->Text = L"MyForm";
                this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
                this->layout->Panel1->ResumeLayout(false);
                this->layout->Panel2->ResumeLayout(false);
                this->layout->Panel2->PerformLayout();
                (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->layout))->EndInit();
                this->layout->ResumeLayout(false);
                (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->graphicSpace))->EndInit();
                (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
                this->ResumeLayout(false);

            }
    #pragma endregion
        private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        }
        private: System::Void splitContainer1_Panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
        }

        private: void PairFormComboBoxInit()
        {
            methods = gcnew List<KeyValuePair < String^, int>>();

            methods->Add(KeyValuePair < String^, int>(L"Равномерное распределение", uniformDistribution));
            methods->Add(KeyValuePair < String^, int>(L"Равномерное распределение в интервале", uniformDistributionInterval));
            methods->Add(KeyValuePair < String^, int>(L"Xor shift 128 битный рандом", xorShift128));
            methods->Add(KeyValuePair < String^, int>(L"Стандартное равномерное распределение", standartUniformRandom));
            methods->Add(KeyValuePair < String^, int>(L"Стандартный рандом", standartRandom));
            methods->Add(KeyValuePair < String^, int>(L"Треугольное распределение", triangle));

            graphics = gcnew List<KeyValuePair < String^, int>>();

            graphics->Add(KeyValuePair < String^, int>(L"График случайного значения от номера попытки", randomValueCurveFromTheAttemptNumber));
            graphics->Add(KeyValuePair < String^, int>(L"Диаграмма повторов", randomValueMatchDiagram));
			graphics->Add(KeyValuePair < String^, int>(L"Диаграмма плотности вероятности", probabilityDistributeDiagram));
        }

    private: System::Void renderBtn_Click(System::Object^ sender, System::EventArgs^ e) 
    {
            try
            {
                auto methodType = (RandomType)(int)method->SelectedValue;
                auto graphicType = (int)graphic->SelectedValue;

                int a,
                    b,
                    c;

                Series^ series1 = gcnew Series();

                // синяя линия
                series1->Color = Color::Blue;
                series1->IsVisibleInLegend = false;
                series1->IsXValueIndexed = true;

                auto randomValues = GetValuesByMethodType(methodType);

                graphicSpace->Series->Clear();

                switch (graphicType)
                {
                    case randomValueCurveFromTheAttemptNumber:
                    {
                        series1->ChartType = SeriesChartType::Line;

                        for (std::size_t i = 0; i < randomValues.size(); i++)
                        {
                            series1->Points->AddXY(i, randomValues[i]);

                            this->dataGridView1->Rows->Add();
                            this->dataGridView1->Rows[i]->Cells[0]->Value = randomValues[i];
                        }
                        break;
                    }
                    case randomValueMatchDiagram:
                    {
                        std::unordered_map<double, double> count;

                        for (auto v : randomValues)
                        {
                            count[v]++;
                        }
                        series1->ChartType = SeriesChartType::BoxPlot;
                        std::size_t i = 0;
                        for (auto v : count)
                        {
                            series1->Points->AddXY(v.first, v.second);
                            this->dataGridView1->Rows->Add();
                            this->dataGridView1->Rows[i]->Cells[0]->Value = v.first;
                            i++;
                        }
                        break;
                    }
                    case probabilityDistributeDiagram:
                    {
                        series1->ChartType = SeriesChartType::Line;

                        Int32::TryParse(this->BId->Text, System::Globalization::NumberStyles::Number,
                            System::Globalization::NumberFormatInfo::CurrentInfo, b);

                        Int32::TryParse(this->AId->Text, System::Globalization::NumberStyles::Number,
                            System::Globalization::NumberFormatInfo::CurrentInfo, a);

                        Int32::TryParse(this->textBox1->Text, System::Globalization::NumberStyles::Number,
                            System::Globalization::NumberFormatInfo::CurrentInfo, c);


                        std::sort(randomValues.begin(), randomValues.end());
                        auto distributing = GetDistributingValuesByMethodType(methodType, randomValues, a, b, c);
                        for (std::size_t i = 0; i < randomValues.size(); i++)
                        {
                            series1->Points->AddXY(randomValues[i], distributing[i]);
                            this->dataGridView1->Rows->Add();
                            this->dataGridView1->Rows[i]->Cells[0]->Value = randomValues[i];
                        }
                        break;
                    }
                }
                std::ofstream fout;
                fout.open("file.txt");
                for (std::size_t i = 0; i < randomValues.size(); i++)
                {
                    fout << randomValues[i] << std::endl;
                }
                fout.close();
                Form::Update();
                graphicSpace->Series->Add(series1);

            }
            catch (const char* msg)
            {
                MessageBox::Show(gcnew String(msg), "Error");
            }
        
    }

    private: std::vector<double> GetValuesByMethodType(RandomType type)
    {

        int n,
            a,
            b,
            c;
        initParam(this->NId->Text, n, 'N');

        std::vector<double> result;
        switch (type)
        {
            case uniformDistribution:
            {
                PRNG rnd;
                for (size_t i = 0; i < n; i++)
                {
                    result.push_back(rnd.random());
                }
                break;
            }
            case triangle:
            {

                initParam(this->AId->Text, a, 'A');

                initParam(this->BId->Text, b, 'B');

                initParam(this->textBox1->Text, c, 'C');

                PRNG rnd(a, b, c);

                for (size_t i = 0; i < n; i++)
                {
                    result.push_back(rnd.TriangleRandom());
                }

                break;
            }
            case uniformDistributionInterval:
            {
                initParam(this->AId->Text, a, 'A');

                initParam(this->BId->Text, b, 'B');

                PRNG rnd(a,b);

                for (size_t i = 0; i < n; i++)
                {
                    result.push_back(rnd.randomInterval());
                }
                break;
            }
            case xorShift128:
            {
                PRNG rnd;
                for (size_t i = 0; i < n; i++)
                {
                    result.push_back(rnd.XorShift128());
                }
                break;
            }
            case standartUniformRandom:
            {

                initParam(this->AId->Text, a, 'A');

                initParam(this->BId->Text, b, 'B');

                PRNG rnd(a,b);
                for (size_t i = 0; i < n; i++)
                {
                    result.push_back(rnd.DefaultUniformRandom());
                }
                break;
            }
            case standartRandom:
            {
                PRNG rnd;
                for (size_t i = 0; i < n; i++)
                {
                    result.push_back(rnd.DefaultRandom());
                }
                break;
            }
        }

        return result;
    }
    private: std::vector<double> GetDistributingValuesByMethodType(RandomType type, 
                                                                    std::vector<double> & randomValues, 
                                                                    int a, 
                                                                    int b, 
                                                                    int c)
    {

        int n = randomValues.size();

        std::vector<double> result;

        switch (type)
        {
        case uniformDistribution:
        {
            PRNG rnd;
            for (size_t i = 0; i < n; i++)
            {
                result.push_back(rnd.randomDistribute(randomValues[i]));
            }
            break;
        }
        case triangle:
        {

            PRNG rnd(a, b, c);

            for (size_t i = 0; i < n; i++)
            {
                result.push_back(rnd.TriangleRandomDistribute(randomValues[i]));
            }

            break;
        }
        case uniformDistributionInterval:
        {

            PRNG rnd(a, b);

            for (size_t i = 0; i < n; i++)
            {
                result.push_back(rnd.randomIntervalDistribute(randomValues[i]));
            }
            break;
        }
        case xorShift128:
        {
            PRNG rnd;
            for (size_t i = 0; i < n; i++)
            {
                result.push_back(rnd.XorShift128Distribute(randomValues[i]));
            }
            break;
        }
        case standartUniformRandom:
        {
            PRNG rnd(a, b);
            for (size_t i = 0; i < n; i++)
            {
                result.push_back(rnd.DefaultUniformRandomDistribute(randomValues[i]));
            }
            break;
        }
        case standartRandom:
        {
            PRNG rnd;
            for (size_t i = 0; i < n; i++)
            {
                result.push_back(rnd.DefaultRandomDistribute(randomValues[i]));
            }
            break;
        }
        }

        return result;
    }
    void initParam(String^ parseString,int& param, char name)
    {
        bool state = Int32::TryParse(parseString, System::Globalization::NumberStyles::Number,
                                    System::Globalization::NumberFormatInfo::CurrentInfo, param);

        if (!state)
        {
            throw "Invalid " + name;
        }
    }
private: System::Void graphicSpace_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
