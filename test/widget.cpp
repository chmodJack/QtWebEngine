#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    view = new QWebEngineView(ui->widget);
    channel = new QWebChannel(this);
    channel->registerObject("QtWidget", this);
    view->page()->setWebChannel(channel);


    //view->settings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
    //view->setAttribute(Qt::WA_DeleteOnClose);
    //view.setWindowFlags(Qt::FramelessWindowHint);
    //view.setAttribute(Qt::WA_TranslucentBackground, true);
    //view->setAttribute(Qt::WA_WState_WindowOpacitySet, true);
    view->resize(800,600);
    view->load(QUrl("file:///C:/Users/qq158/Desktop/QtWeb/index.html"));
    view->show();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::jsVisibleFunc(const QString& str)
{
    ui->textEdit->append(str);
}

void Widget::on_call_js_function_released()
{
    view->page()->runJavaScript("append_text_to_textarea1(\"call js function from qt cxx \")");
}
