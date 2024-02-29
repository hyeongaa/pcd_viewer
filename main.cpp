#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <chrono>
#include <thread>

int main (int argc, char** argv)
{
  // PCD 파일 경로와 이름을 확인합니다.
  if (argc != 2)
  {
    std::cerr << "Usage: " << argv[0] << " <input.pcd>" << std::endl;
    return (-1);
  }

  // PCD 파일에서 포인트 클라우드를 읽어옵니다.
  pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGBA>);
  if (pcl::io::loadPCDFile<pcl::PointXYZRGBA> (argv[1], *cloud) == -1)
  {
    PCL_ERROR ("Couldn't read file %s \n", argv[1]);
    return (-1);
  }

  // 시각화 객체를 생성합니다.
  pcl::visualization::PCLVisualizer viewer ("3D Viewer");
  viewer.setBackgroundColor (0, 0, 0);
  viewer.addPointCloud<pcl::PointXYZRGBA> (cloud, "sample cloud");
  viewer.setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");
  viewer.setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_OPACITY, 0.5, "sample cloud");
  // 시각화를 업데이트하고 창을 유지합니다.
  while (!viewer.wasStopped ())
  {
    viewer.spinOnce (100);
    std::this_thread::sleep_for(std::chrono::microseconds(100000));
  }
  return (0);
}
