#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QWebEngineView>
#include <QWebChannel>
#include <QWebEngineSettings>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_call_js_function_released();

private:
    Ui::Widget *ui;

    QWebEngineView* view;
    QWebChannel* channel;
public:
    Q_PROPERTY(QString jsVisibleVar MEMBER name)
    QString name="chmodJack";

    Q_INVOKABLE
    void jsVisibleFunc(const QString& str);
};
#endif // WIDGET_H
