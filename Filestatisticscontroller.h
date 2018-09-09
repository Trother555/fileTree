#ifndef STATISTICSCONTROLLER_H
#define STATISTICSCONTROLLER_H

#include <QObject>
#include "statisticsworker.h"

class FileStatisticsController : public QObject
{
    Q_OBJECT

    StatisticsWorker worker;

public:
    explicit FileStatisticsController(QObject *parent = nullptr);
    ~FileStatisticsController();
signals:
    void updated(const QString& statistics);
public slots:
    void updateStatistics(const QModelIndex& index);
};

#endif // STATISTICSCONTROLLER_H
