#include "statisticsworker.h"
#include <QDirIterator>
#include <QDir>
#include <memory>

StatisticsWorker::StatisticsWorker()
{

}

void StatisticsWorker::setPath(const QString &p)
{
    path = p;
}

void StatisticsWorker::run()
{
    QDirIterator it("C:/Users/Pavel/Desktop/asd/"+path, QStringList() << "*",
                    QDir::Files,QDirIterator::Subdirectories);
    FileStatisticsModel model;
    while (it.hasNext())
    {
        model.updateModel(it.fileInfo());
        it.next();
    }
    statistics = model.toString();
    emit ready(statistics);
}
