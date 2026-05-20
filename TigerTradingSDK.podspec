#
# Be sure to run `pod lib lint TigerTradingSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'TigerTradingSDK'
  s.version          = '0.1.0'
  s.summary          = 'A short description of TigerTradingSDK.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/luopengfei/TigerTradingSDK'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'luopengfei' => 'luopengfei@itiger.com' }
  s.source           = { :git => 'https://github.com/luopengfei/TigerTradingSDK.git', :tag => s.version.to_s }

  s.ios.deployment_target = '12.0'

  s.source_files = 'TigerTradingSDK/Classes/**/*'
  
  s.resource_bundles = {
      'TigerTrading_Privacy' => ['Classes/PrivacyInfo.xcprivacy'],
  }
  
  s.swift_version = "5.0"
  s.pod_target_xcconfig = { "DEFINES_MODULE" => "YES" }
  

  s.vendored_frameworks = "TigerTradingSDK/Frameworks/*.{framework,xcframework}"
  s.dependency 'libpag', '4.3.62'
  s.dependency 'AFNetworking'
  s.dependency 'MJRefresh'
  s.dependency 'Masonry'
  s.dependency 'Mantle'
  s.dependency 'SDWebImage'
  s.dependency 'MBProgressHUD'
  s.dependency 'FMDB'
  s.dependency 'Protobuf', '3.26.1'
  s.dependency 'FLAnimatedImage'
  s.dependency 'ReactiveObjC'
  s.dependency 'MqttCocoaAsyncSocket'
  s.dependency 'PromisesObjC'
  s.dependency 'PromisesSwift'
  s.dependency 'CocoaLumberjack'

  s.dependency 'YYText'
  s.dependency 'YYModel'
  s.dependency 'YYCategories', '1.0.4'
  s.dependency 'MMKV'
  s.dependency 'MMKVCore'

  
  s.dependency 'RecaptchaEnterprise','18.7.0'
  s.dependency 'Intercom', '9.3.5.2'
  s.dependency 'GTCaptcha4', '1.8.8'
  
end
