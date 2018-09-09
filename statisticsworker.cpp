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
    model.clean();
    QDirIterator it(path, QStringList() << "*",
                    QDir::Files,QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        model.updateModel(it.fileInfo());
        it.next();
    }
    emit ready(model);
}
