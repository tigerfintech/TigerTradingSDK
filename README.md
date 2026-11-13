# TigerTradingSDK Demo

本示例使用 SDK **3.2.2**，最低支持 iOS 15。Standard 和 US 共用一份源码、资源及配置入口，分别集成对应的公开 SDK。

| 版本 | Target | Scheme | Pod |
| --- | --- | --- | --- |
| Standard | TigerQuoteSDK_Example | TigerQuoteSDK-Example | TigerTradingSDK |
| US | TigerQuoteSDK_Example_US | TigerQuoteSDK-Example-US | TigerTradingSDKUS |

SDK 版本与对应发布 tag 记录在 [release.json](release.json)。SDK 二进制和三方依赖通过 CocoaPods 安装，仓库不包含 Pods 或 SDK 二进制。

## 配置与运行

1. 在 [TBExampleConfig.m](Example/TigerQuoteSDK/Config/TBExampleConfig.m) 填写 `appName`、`appSecret`、`tenantId`。默认网络为 `TigerTradingSDKNetWork_UAT_ITFS`，可按接入环境调整。
2. 确保本机的 `pod` 命令可用，在 `Example` 目录执行：

   ```sh
   pod install --repo-update
   ```

3. 打开 `Example/TigerQuoteSDK.xcworkspace`，选择上表中对应的 scheme。安装依赖后使用 workspace。
4. 在所选 target 的 Signing & Capabilities 中设置自己的 Team 和 Bundle Identifier，再选择设备运行。Standard / US 默认使用不同的 Bundle ID；同时安装时也需保持不同。

两个 target 的 SDK 版本一致，不在同一 target 混装两种 SDK。Core 及三方依赖由公开 Podspec 解析。

## 登录、交易与示例范围

配置填写完成后，登录授权和交易授权仍需按客户接入流程由宿主提供。本示例没有内部账号、Mock 登录、测试密码或预置交易授权。

公共示例保留页面跳转、模块嵌入、宿主代理、自定义行情和日志导出等集成用法。源码不包含内部配置目录及内部测试工具。

SDK 对设备架构、模拟器和系统版本的支持，以所用 SDK 的发布说明为准；本 Demo 的最低系统版本不代表 SDK 的最低系统版本。

SDK 的隐私清单由其二进制及依赖提供。应用自身新增的功能与系统 API 使用，需按应用实际情况维护自己的隐私清单。

## 常见检查

- **缺少 Pods 或模块**：在 `Example` 目录安装依赖，并打开 workspace。
- **签名失败**：核对当前 target 的 Team、Bundle ID 和设备签名条件。
- **启动时配置断言**：检查三项必要配置是否已填写。

## License

许可说明见 [LICENSE](LICENSE)。
