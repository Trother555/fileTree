#include "filestatisticsmodel.h"

FileStatisticsModel::FileStatisticsModel(const QString &p)
{
    path = p;
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
    result += path;
    result += ":\nFiles count: " + QString::number(filesCount);
    result += "\nAll size: " + QString::number(allSize/1024/1024) + " Mb\nAvg size per extension:\n";
    for(auto it : avgSizePerExt.keys())
    {
        result += it + " : " + QString::number(avgSizePerExt.value(it).first/1024) + " Kb\n";
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
    auto extension = file.suffix().toLower();
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
