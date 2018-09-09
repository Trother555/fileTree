#ifndef STATISTICSVIEW_H
#define STATISTICSVIEW_H

#include <QObject>
#include <QTextBrowser>
#include <QTableView>

class FileStatisticsViewContainer : public QObject
{
    Q_OBJECT

    QTextBrowser *view;
public:
    FileStatisticsViewContainer();
    void setView(QTextBrowser* label);

public slots:
    void updateView(const QString& statistics);
};

#endif // STATISTICSVIEW_H
