#include "filestatisticsviewcontainer.h"

FileStatisticsViewContainer::FileStatisticsViewContainer()
{

}

void FileStatisticsViewContainer::setView(QTextBrowser *l)
{
    view = l;
}


void FileStatisticsViewContainer::updateView(const QString& statistics)
{
    view->setText(statistics);
}
