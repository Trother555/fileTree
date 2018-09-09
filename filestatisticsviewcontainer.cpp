#include "filestatisticsviewcontainer.h"

FileStatisticsViewContainer::FileStatisticsViewContainer()
{

}

void FileStatisticsViewContainer::setFileCountView(QLabel *l)
{
    fileCount = l;
}

void FileStatisticsViewContainer::setAllSizeView(QLabel *l)
{
    allSize = l;
}

void FileStatisticsViewContainer::setAvgSizeView(QTableView *t)
{
    avgSizePerExt = t;
}

void FileStatisticsViewContainer::updateView(const FileStatisticsModel& model)
{
    fileCount->setText(QString(model.getFilesCount()));
    allSize->setText(QString::number(model.getAllSize()));
}
