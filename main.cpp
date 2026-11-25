#include <iostream>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>

int main() {
    // 1. Создаем облако точек
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

    // 2. Загружаем из файла
    std::string filename = "table_scene_lms400.pcd";
    if (pcl::io::loadPCDFile<pcl::PointXYZ>(filename, *cloud) == -1) {
        std::cerr << "Не удалось загрузить файл " << filename << std::endl;
        return -1;
    }

    std::cout << "Загружено точек: " << cloud->size() << std::endl;

    // 3. Визуализация (используем более мощный PCLVisualizer)
    pcl::visualization::PCLVisualizer viewer("3D Viewer");
    viewer.setBackgroundColor(0.1, 0.1, 0.1); // Тёмный фон

    // Добавляем облако с именем "cloud"
    viewer.addPointCloud<pcl::PointXYZ>(cloud, "cloud");
    viewer.setPointCloudRenderingProperties(
        pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud"
    );

    // Добавляем систему координат
    viewer.addCoordinateSystem(0.1);

    // Начальный ракурс камеры
    viewer.initCameraParameters();

    std::cout << "Нажми 'q' для выхода" << std::endl;

    while (!viewer.wasStopped()) {
        viewer.spinOnce(100);
    }

    return 0;
}