#include "filestatisticsmodel.h"

FileStatisticsModel::FileStatisticsModel()
{

}

uint32_t FileStatisticsModel::getFilesCount() const
{
    return filesCount;
}

double FileStatisticsModel::getAllSize() const
{
    return allSize;
}

QString FileStatisticsModel::toString()
{
    QString result;
    result += QString::number(filesCount);
    result += QString::number(allSize);
    for(auto it : avgSizePerExt)
    {
        //TODO
    }
    return result;
}

void FileStatisticsModel::updateModel(QFileInfo file)
{
    //update files count
    filesCount++;
    auto size = file.size();
    //update files size
    allSize += size;
    auto extension = file.completeSuffix();
    //update avarage by extension
    if(avgSizePerExt.contains(extension))
    {
        //inc samples count
        avgSizePerExt[extension].second ++;
        //eval cumulative moving average
        avgSizePerExt[extension].first =
                avgSizePerExt[extension].first +
                (double)(size-avgSizePerExt[extension].first)/
                avgSizePerExt[extension].second;
    }
    else
    {
        avgSizePerExt.insert(extension, SumAndCount(size, 1));
    }
}
