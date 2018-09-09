#ifndef STATISTICSCONTROLLER_H
#define STATISTICSCONTROLLER_H

#include <QObject>
#include "statisticsworker.h"
#include "filestatisticsmodel.h"

class FileStatisticsController : public QObject
{
    Q_OBJECT

    StatisticsWorker worker;
    FileStatisticsModel *model;

public:
    explicit FileStatisticsController(QObject *parent = nullptr);
    void setModel(FileStatisticsModel *model);
    ~FileStatisticsController();

public slots:
    void updateStatistics(const QModelIndex& path);
};

#endif // STATISTICSCONTROLLER_H
