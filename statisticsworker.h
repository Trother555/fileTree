#ifndef STATISTICSWORKER_H
#define STATISTICSWORKER_H

#include <QObject>
#include <QThread>
#include "filestatisticsmodel.h"

class StatisticsWorker : public QThread
{
    Q_OBJECT

    FileStatisticsModel model;
    QString path;
    void run() override;

public:
    StatisticsWorker();
    void setPath(const QString&path);

signals:
    void ready(const FileStatisticsModel&result);
};

#endif // STATISTICSWORKER_H
