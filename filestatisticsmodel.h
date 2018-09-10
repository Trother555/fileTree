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

    QString path;
    uint32_t filesCount = 0;
    double allSize = 0;
    uint32_t subdirs = 0;
    QMap<QString, SumAndCount> avgSizePerExt;

public:
    FileStatisticsModel(const QString &path);
    void updateModel(QFileInfo file);
    void setSubdirsCount(uint32_t count);
    uint32_t getFilesCount() const;
    double getAllSize() const;
    void clean();
    QString toString();
};

#endif // STATISTICSMODEL_H
