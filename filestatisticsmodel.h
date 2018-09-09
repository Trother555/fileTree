#ifndef STATISTICSMODEL_H
#define STATISTICSMODEL_H

#include <QObject>
#include <QPair>
#include <QMap>
#include <QFileInfo>

typedef QPair<double, uint32_t> SumAndCount;

class FileStatisticsModel : public QObject
{
    Q_OBJECT

    uint32_t filesCount;
    double allSize;
    QMap<QString, SumAndCount> avgSizePerExt;

public:
    FileStatisticsModel();

    void updateModel(QFileInfo file);

    uint32_t getFilesCount() const;
    double getAllSize() const;
    void clean();

signals:
    void modelChanged(const FileStatisticsModel& newModel);
public slots:
    void setModel(const FileStatisticsModel& newModel);

};

#endif // STATISTICSMODEL_H
