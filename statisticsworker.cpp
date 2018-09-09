#include "statisticsworker.h"
#include <QDirIterator>
#include <QDir>
#include <memory>
#include <QElapsedTimer>

StatisticsWorker::StatisticsWorker()
{

}

void StatisticsWorker::setPath(const QString &p)
{
    path = p;
}

void StatisticsWorker::stop()
{
    stopped = true;
}

void StatisticsWorker::run()
{
    stopped = false;
    QDirIterator it(path, QStringList() << "*",
                    QDir::Files,QDirIterator::Subdirectories);
    FileStatisticsModel model(path);
    QElapsedTimer timer;
    timer.start();
    statistics = "In process\n" + model.toString();
    emit ready(statistics);
    while (it.hasNext() && !stopped)
    {
        model.updateModel(it.fileInfo());
        it.next();
        auto elapsed = timer.elapsed();
        if(elapsed>500)
        {
            timer.start();
            statistics = "In process\n" + model.toString();
            emit ready(statistics);
        }
    }
    if(sopped)
    {
        qDebug()<<"Worker interrupted";
    }
    else
    {
        qDebug()<<"Worker done";
    }
    statistics = model.toString();
    emit ready(statistics);
}
