#ifndef STATISTICSVIEW_H
#define STATISTICSVIEW_H

#include <QObject>
#include <filestatisticsmodel.h>
#include <QLabel>
#include <QTableView>

class FileStatisticsViewContainer : public QObject
{
    Q_OBJECT

    QLabel *fileCount;
    QLabel *allSize;
    QTableView *avgSizePerExt;

public:
    FileStatisticsViewContainer();
    void setFileCountView(QLabel* label);
    void setAllSizeView(QLabel* label);
    void setAvgSizeView(QTableView *table);

public slots:
    void updateView(const FileStatisticsModel& model);
};

#endif // STATISTICSVIEW_H
