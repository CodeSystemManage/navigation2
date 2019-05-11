// Copyright (c) 2018 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License. Reserved.

#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "nav2_recoveries/spin.hpp"
#include "nav2_recoveries/back_up.hpp"
#include "nav2_recoveries/stop.hpp"

int main(int argc, char ** argv)
{
  // Force flush of the stdout buffer.
  setvbuf(stdout, NULL, _IONBF, BUFSIZ);

  rclcpp::init(argc, argv);

  auto recoveries_node = rclcpp::Node::make_shared("recoveries");

  auto spin = std::make_shared<nav2_recoveries::Spin>(
    recoveries_node);

  auto back_up = std::make_shared<nav2_recoveries::BackUp>(
    recoveries_node);

  auto stop = std::make_shared<nav2_recoveries::Stop>(
    recoveries_node);

  rclcpp::spin(recoveries_node);
  rclcpp::shutdown();

  return 0;
}