var bridge = {
    default: this,
    call: function(b, a, c) {
        var e = "";
        "function" == typeof a && ((c = a), (a = {}));
        a = {
            data: void 0 === a ? null : a
        };
        if ("function" == typeof c) {
            var g = "dscb" + window.dscb++;
            window[g] = c;
            a._dscbstub = g;
        }
        console.log(b, ":", a);
        a = JSON.stringify(a);
        if (window._TigerBridge) e = _TigerBridge.call(b, a);
        else if (
            window._dswk ||
            -1 != navigator.userAgent.indexOf("_TigerBridge")
        )
            e = prompt("_TigerBridge=" + b, a);
        return JSON.parse(e || "{}").data;
    },

    formatArray: function (arr) {
        if (Array.isArray(arr)) {
            return arr.join(',');
        }
        return arr;
    },

    object2JSONStr: function (obj) {
        if (typeof obj === 'object') {
            return JSON.stringify(obj);
        }
        return obj;
    },

    JSONStr2Object: function (str) {
        if (typeof str === 'string') {
            try {
                return JSON.parse(str);
            } catch (e) {
                return str;
            }
        }
        return str;
    },

    register: function(b, a, c) {
        c = c ? window._dsaf : window._dsf;
        window._dsInit ||
            ((window._dsInit = !0),
            setTimeout(function() {
                bridge.call("_dsb.dsinit");
            }, 0));
        "object" == typeof a ? (c._obs[b] = a) : (c[b] = a);
    },

    registerAsyn: function(b, a) {
        this.register(b, a, !0);
    },

    hasNativeMethod: function(b, a) {
        return this.call("_dsb.hasNativeMethod", {
            name: b,
            type: a || "all"
        });
    },

    disableJavascriptDialogBlock: function(b) {
        this.call("_dsb.disableJavascriptDialogBlock", {
            disable: !1 !== b
        });
    },

    testData: function(b) {
        return this.call("testData", b);
    },

    /**
     * @description 判断用户登录状态，如果是游客则跳转到 注册页面 并返回true；如果是 三方登录账号且尚未绑定过手机号，则跳转到绑定手机号页面 返回true；正常用户直接返回false
     *
     * @returns {boolean}
     *
     * @platform iOS
     * @app TradeUp | TigerTrade
     */
    isAccountPermissionLimited: function() {
        return this.call("isAccountPermissionLimited");
    },

    /**
     * @description 退出当前web页
     *
     * @platform iOS | Android
     * @app TradeUp | TigerTrade
     */
    quit: function() {
        return this.call("quit");
    },

    /**
     * @description 期权答题
     *
     * @platform iOS
     * @app TradeUp
     */
    opt_risk_confirm: function() {
        return this.call("opt_risk_confirm");
    },

    /**
     * @description 清除所有cookie和缓存
     *
     * @platform iOS
     * @app TradeUp | TigerTrade
     */
    clearCookiesAndCache: function() {
        return this.call("clearCookiesAndCache");
    },

    /**
     * @description 清除所有cookie和缓存
     *
     * @param domain: 指定域
     * @param name: 域名
     * @platform iOS
     * @app TradeUp
     */
    clearCookie: function(domain, name) {
        return this.call(
            "clearCookie",
            {
                domain: domain,
                name: name
            }
        );
    },

    /**
     * @description：跳转到开户选择国家页
     * @platform iOS | Android
     * @app TradeUp
     */
    goOpenAccount: function() {
        return this.call("goOpenAccount");
    },

    /**
     * 获取二次信息：在活动页面后，然后用户点击返回，还是关闭按钮，某些业务要求弹窗提示信息给用户
     * @param msg: 信息内容
     * @platform iOS | Android
     * @app TradeUp
     */
    getAlertMessage: function(msg) {
        return this.call("getAlertMessage", { msg: msg });
    },

    /**
     * @description：监听路由hash改变（客户端注入js实现）
     * @platform iOS | Android
     * @app TradeUp
     */
    onHashChange: function() {
        return this.call("onHashChange");
    },

    /**
     * 获取当前登录用的access token
     * @platform iOS | Android
     * @app TigerTrade | TradeUp
     */
    getAccessToken: function() {
        return this.call("getAccessToken");
    },

    /**
     * @description：短信分享
     * @param {string} content: 短信内容
     * @platform iOS | Android
     * @app TradeUp
     */
    shareMessage: function(content) {
        return this.call("shareMessage", { content: content });
    },

    /**
     * @description：邮件分享，需要 app 内登陆原生邮箱可启用
     * @param {string} subject: 邮件主题
     * @param {string} content: 邮件内容
     * @param {object} callback: 回调函数 success/fail/complete
     * @platform iOS/Android
     * @app TradeUp
     */
    shareEmail: function(subject, content, callback) {
        return this.call(
            "shareEmail",
            Object.assign({ subject: subject, content: content }, callback)
        );
    },

   /**
     * @description 邮件分享 v2，需要 app 内登陆原生邮箱可启用，支持收件人
     * @param {object} config   参数 
     * @param {string}          config.subject 邮件主题 
     * @param {string}          config.content 邮件内容
     * @param {array<string>|string}   config.recipients 收件人  （数组字符串或者字符串均可）
     * @param {object} callback: 回调函数 success/fail/complete
     * @platform iOS/Android
     * @app TradeUp
     */
    shareEmailV2: function(config, callback) {
        return this.call(
            "shareEmailV2",
            Object.assign({
                subject: config.subject,
                content: config.content,
                recipients: this.formatArray(config.recipients)
            }, callback)
        );
    }, 

    /**
     * @description：根据图片base64数据分享图片
     * @param {string} picData: base64 string  支持数组
     * @param {object} callback: 回调函数 success/fail/complete
     * @platform iOS | Android
     * @app TigerTrade | TradeUp
     */
    sharePicFromData: function(picData, callback) {
        return this.call("sharePicFromData", Object.assign(callback, { picData: this.formatArray(picData) }));
    },

    /**
     * @description：分享手机截屏
     * @platform iOS | Android
     * @app TigerTrade | TradeUp
     * @param {object} callback: 回调函数 success/fail/complete
     */
    shareScreenshot: function(callback) {
        return this.call("shareScreenshot", Object.assign({}, callback));
    },

    /**
     * @description：通过url地址分享图片
     * @param {object} config { album: [], success, fail 等 } 其中album可以为数组
     * @platform iOS/Android
     * @app TigerTrade/TradeUp
     */
    sharePicAlbum: function(config) {
        if (typeof config.album === 'string') {
            config.album = [config.album];
        }
        return this.call("sharePicAlbum", Object.assign({}, config ));
    },

    /**
     * @description：更新分享数据 给客户端传分享数据
     * @param {object} config  参数及回调混合 { title, desc, url, img, success, fail, complete }
     * @platform iOS/Android
     * @app TigerTrade/TradeUp
     */
    updateData: function(config) {
        return this.call(
            "updateData",
            Object.assign({}, this.JSONStr2Object(config))
        );
    },
    
    /**
     * @description：web页面调起分享，并携带着分享数据
     * @param {object} config  参数及回调混合 { title, desc, url, img, success, fail, complete }
     * @platform iOS/Android
     * @app TigerTrade/TradeUp
     */
    shareWithParam: function(config) {
        return this.call(
            "shareWithParam",
            Object.assign({}, this.JSONStr2Object(config))
        );
    },

    /**
     * @description：唤起分享
     * @param { string | string[] } platform?
     * @platform iOS | Android
     * @app TigerTrade | TradeUp
     */
    share: function(platform) {
        return this.call("share", { platform: this.formatArray(platform) });
    },

    /**
     * @description：设置webview页面标题
     * @param { string } title: 标题
     * @platform iOS | Android
     * @app TigerTrade | TradeUp
     */
    setTitle: function(title) {
        return this.call("setTitle", { title: title });
    },

    /**
     * @description：获取设备ID
     * @platform iOS | Android
     * @app TigerTrade | TradeUp
     */
    getDeviceID: function() {
        return this.call("getDeviceID");
    },

    /**
     * @description：唤起/要求交易密码输入
     * @param {object} callback: 回调函数 success/fail/complete
     * @platform iOS | Android
     * @app TigerTrade | TradeUp
     */
    verifyTradePassword: function(callback) {
        return this.call("verifyTradePassword", Object.assign({}, callback));
    },

    /**
     * @description：安全机制检查
     * @param {object} config  { code, token }
     * @platform iOS | Android
     * @app TigerTrade | TradeUp
     */
    securityCheck: function(securityParam) {
        return this.call(
            "securityCheck",
            { securityParam: this.object2JSONStr(securityParam) }
        );
    },

    /**
     * @description：获取当前登录用户的trade token
     * @returns { string }
     * @platform iOS | Android
     * @app TigerTrade | TradeUp
     */
    getTradeToken: function() {
        return this.call("getTradeToken");
    },
    
    /**
     * @description：获取当前登录用户的uuid
     * @returns { string }
     * @platform iOS | Android
     * @app TigerTrade | TradeUp
     */
    getUUID: function() {
        return this.call("getUUID");
    },

    /**
     * @description：更新用户状态
     * @platform iOS | Android
     * @app TigerTrade | TradeUp
     */
    updateUserStatus: function() {
        return this.call("updateUserStatus");
    },

    /**
     * @description：启用/禁用右上角分享
     * @param { boolean } enabled
     * @platform iOS | Android
     * @app TigerTrade | TradeUp
     */
    enableNativeShare: function(enabled) {
        return this.call("enableNativeShare", { enabled: enabled });
    },

    /**
     * @description：H5页面从不可见变为可见时，调用webView.loadUrl("javascript:window.location.reload()")
     * 重新刷新下H5。在需要的刷新的页面直接调用一次即可。
     * @param { boolean } enabled
     * @platform iOS | Android
     * @app TradeUp
     */
    enableNativeReload: function(enabled) {
        return this.call("enableNativeReload", { enabled: enabled });
    },

    /**
     * @description：调用后如果用户未开通两步验证，会走native的开启两步验证流程；如果已开通两步验证，会开启新网页打开入金页面。
     * @platform iOS | Android
     * @app TradeUp
     */
    gotoDeposit: function() {
        return this.call("gotoDeposit");
    },

    /**
     * @description：跳转app页面
     * @param { string } path
     * @platform iOS | Android
     * @app TigerTrade | TradeUp
     */
    goNativePage: function(path) {
        return this.call("goNativePage", { path: path });
    },
    
    /**
     * @description：跳转老虎令牌
     * @param { object } config
     * @platform iOS | Android
     * @app TigerTrade
     */
    goTigerKey: function(config) {
        return this.call("goTigerKey", config);
    },
    
    /**
     * 开启MyInfo登录
     */
    openMyInfo: function(config) {
        return this.call("openMyInfo", config);
    },
    
    
    /**
     * 跳转App系统设置
     */
    openSystemSetting: function() {
        return this.call("openSystemSetting");
    },

    /**
     * @description：要求用户绑定手机（即跳转绑定手机页面）
     * @platform iOS | Android
     * @app TigerTrade | TradeUp
     */
    requirePhoneAccount: function() {
        return this.call("requirePhoneAccount");
    },

    /**
     * 获取版本信息
     * @platform iOS | Andorid
     * @app TigerTrade | TradeUp
     */
    getVersions: function() {
        return this.call("getVersions");
    },
    
    /**
     * 获取自研客户系统需要的信息
     * @platform iOS | Andorid
     * @app TigerTrade
     */
    getImInfo: function() {
        return this.call("getImInfo");
    },

    openWechat: function() {
        return this.call("openWechat");
    },
    
    /**
     * 弹出引导打分弹层
     */
    showRateApp: function() {
        return this.call("showRateApp");
    },
    
    /**
     * 跳转到微信小程序
     * @param string json，包含userName和path
     */
    goToWeChatMiniProgram: function(json) {
        return this.call("goToWeChatMiniProgram", json);
    },

    /**
     * @description 在新的webview页面中打开链接
     *
     * @param {string} url
     * @param {string} title?
     * @returns {void} 无
     *
     * @platform iOS | Android
     * @app TradeUp | TigerTrade
     */
    openInNewPage: function(url, title) {
        return this.call(
            "openInNewPage",
            { url: url, title: title }
        )
    },

    /**
     * @description
     * 获取用户类型
     * 0: 手机号用户
     * 1: 游客
     * 2: 三方账号但未绑定手机
     *
     * @param 无
     * @returns {number}
     *
     * @platform iOS | Android
     * @app TradeUp | TigerTrade
     */
    getUserStatus: function() {
        return this.call("getUserStatus")
    },

    /**
     * @description singpass第三方登录授权后，回调页面调用原生app的该方法，将获得的授权码提供给原生app
     *
     * @param {string} code
     * @param {string} msg
     * @returns {void} 无
     *
     * @platform iOS | Android
     * @app TradeUp | TigerTrade
     */
    singpassCallback: function(code, msg) {
        return this.call(
            "singpassCallback",
            { code: code, msg: msg }
        )
    },
    
    /**
     * @description 用于 singpass 登录
     *
     * @param {object} params
     * @param {string} params.code
     * @param {string} params.nonce
     * @param {string} params.state 可选
     *
     * @platform iOS | Android
     * @app TigerTrade
     */
    singpassAuthCallback: function(params) {
        return this.call("singpassAuthCallback", params)
    },


    /**
     * @description 苹果内购
     *
     * @param {string} id -- 商品id
     * @param {string} paymentId -- 订单id
     * @returns {void} 无
     *
     * @platform iOS
     * @app TradeUp | TigerTrade
     */
    callInAppPay: function(id, paymentId) {
        return this.call(
            "callInAppPay",
            { id: id, paymentId: paymentId }
        )
    },

    /**
     * @description 在手机浏览器中打开链接
     *
     * @param {string} link
     * @returns {void} 无
     *
     * @platform iOS | Android
     * @app TigerTrade
     */
    openUrlBySystemBrowser: function(link) {
        return this.call(
            "openUrlBySystemBrowser",
            { link: link }
        )
    },

    /**
     * @description 是否开启ios回弹效果 默认开启
     *
     * @param {boolean} enabled
     * @returns {void} 无
     *
     * @platform iOS
     * @app TigerTrade
     */
    enableWebViewBounce: function(enabled) {
        return this.call(
            "enableWebViewBounce",
            { enabled: enabled }
        )
    },

    /**
     * @description 获取当前牌照版本
     *
     * @param 无
     * @returns {string} 当前牌照版本
     *
     * @platform iOS | Android
     * @app TigerTrade
    */
    getEdition: function() {
        return this.call("getEdition")
    },

    /**
     * @description: 基金超市-基金购买页跳转
     * @param fundId: 基金id fundId
     * @param fundName: 基金名称 fundName
     * @platform iOS | Android
     * @app TigerTrade v6.7.5
     */
    openFundPurchasePage: function(fundId, fundName) {
        return this.call(
            "openFundPurchasePage",
            { fundId: fundId, fundName: fundName }
        )
    },

    /**
     * @description 分享base64图片，客户端在图片底部拼接logo和二维码
     *
     * @param {string | string[]} album
     * @param {object} callback
     *
     * @platform iOS
     * @app TigerTrade
     */
    sharePicWithLogoFromData: function(album, callback) {
        return this.call(
            "sharePicWithLogoFromData",
            Object.assign(callback, { album: album })
        )
    },

    /**
     * @description 开通华美银行账户的入口相关，回退到开户首页
     *
     * @platform iOS
     * @app TradeUp | TigerTrade
     */
    disallowGoBack: function() {
        return this.call("disallowGoBack")
    },

    /**
     * @description 打分评论
     *
     * @platform iOS | Android
     * @app TigerTrade
     */
    showFeedbackDialog: function() {
        return this.call("showFeedbackDialog")
    },

    /**
     * @description 港股level切换设备
     *
     * @platform iOS | Android
     * @app TigerTrade
     * @param { string } nope 该参数无意义
     * @param { object } callback { fail, success } 回调函数
     */
    deviceSwitch: function(nope, callback) {
        return this.call("deviceSwitch", Object.assign({}, callback))
    },

    /**
     * @description 用于神策埋点
     *
     * @param {string} type
     * @param {string} name
     *
     * @platform iOS | Android
     * @app TigerTrade
     */
    onAppBehavior: function(type, name) {
        return this.call(
            "onAppBehavior",
            { type: type, name: name }
        )
    },

    /**
     * @description 神策统计页面时长，第一个参数是event，第二个参数是properties（json形式）
     *
     * @param {string} event
     * @param {object} properties
     *
     * @platform iOS
     * @app TigerTrade
     */
    trackTimer: function(event, properties) {
        return this.call(
            "trackTimer",
            { event: event, properties: this.object2JSONStr(properties) }
        )
    },

    /**
     * @description 神策统计页面时长结束事件
     *
     * @platform iOS
     * @app TigerTrade
     */
    onTrackTimerEnd: function() {
        return this.call("onTrackTimerEnd")
    },

    /**
     * @description 行情权限开通标准账户
     *
     * @platform iOS
     * @app TigerTrade
     */
    gotoOpenOmnibusAccountForStockPermission: function() {
        return this.call("gotoOpenOmnibusAccountForStockPermission")
    },

    /**
     * @description
     * 设置标题栏颜色
     * a为标题栏背景色，值为ffffff这种十六进制，不带#, theme 用于区分背景适合黑皮肤还是白皮肤，值为black和white
     *
     * @param {string} a
     * @param {white | black} theme
     *
     * @platform iOS | Android
     * @app TigerTrade
     * *该方法暂时不存在window.TigerBridge里
     */
    setNavBarColor: function(color, theme) {
        return this.call(
            "setNavBarColor",
            { color: color, theme: theme }
        )
    },

    /**
     * @description 跳转开户页
     *
     * @platform iOS
     * @app TigerTrade
     */
    openAccountPage: function() {
        return this.call("openAccountPage")
    },

    /**
     * @description 获取用户授权推送一条微信公众号模版消息
     * 暂不支持回传用户微信相关信息，可以后续添加
     * @platform iOS ｜ android
     * @app TigerTrade v6.8.0
     */
    openWechatAndSubscribe: function () {
        return this.call('openWechatAndSubscribe');
    },
    /**
     * @description 用户关闭webview时的触发的回调 (提醒的内容，需要web自己做) (app端会禁止导航栏响应)，需要在关闭前执行，常在组件didmount时即执行
     *
     * @platform iOS/Android
     * @app TradeUp
     * @param {object} callback  回调，包含了 { success, fail }
     */
    needCloseConfirm: function (callback) {
        return this.call("needCloseConfirm", Object.assign({}, callback ))
    },

    /**
     * @description 关闭提醒回调 (需要与needCloseConfirm配对使用)  显示弹窗时，app端会禁止导航栏响应，hideCloseConfirm相当于告诉app端弹窗消失了，放开响应
     *
     * @platform iOS/Android
     * @app TradeUp
     */
    hideCloseConfirm: function () {
        return this.call("hideCloseConfirm")
    },

    /**
     * @description 获取用户当前的位置
     *
     * @platform iOS/Android
     * @app TigerTrade
     */
    getLocation: function () {
        return this.call("getLocation")
    },

    /**
     * @description 获取用户开户时选择的国家
     *
     * @platform iOS/Android
     * @app TigerTrade
     */
    getRegion: function () {
        return this.call("getRegion")
    },

    /**
     * @description 获取用户开户在哪个牌照下 'TBNZ' 和 'TBSG'
     *
     * @platform iOS/Android
     * @app TigerTrade
     */
    getLicense: function () {
        return this.call("getLicense")
    },

    /**
     * @description：是否开启ios页面全屏效果（不显示页面顶部title bar)
     * @param { boolean } enabled
     * @platform iOS
     * @app TigerTrade
     */
    jsEnableWebViewFullScreen: function(enabled) {
        return this.call("jsEnableWebViewFullScreen", { enabled: enabled });
    },
    /**
     webView深度定制
     @param fullScreen YES:全屏显示（隐藏导航栏和状态栏）；NO:（显示导航栏和状态栏）
     @param useSafeArea YES:直接到最下面（主要针对刘海屏系列手机）no：不使用安全区域
     @param style 0为深色皮肤，1为浅色皮肤，-1跟着app走，不定制
     @param navbar    boolean    true: 上滑时展示导航条，false：上滑时不展示导航条(9.2.0支持)
     * @description IOS TigerTrade 6.8.9 版本新增该方法
     */
    jsDeepCustomWebViewFullScreen: function(fullScreen,useSafeArea,style,navbar) {
        return this.call("jsDeepCustomWebViewFullScreen", {fullScreen:fullScreen,
            style: style,
            navbar: typeof navbar === 'boolean' ? navbar :  true,
            useSafeArea:useSafeArea });
    },
    /**
     * 设置是否启用右滑退出webview手势
     * @params enabled true 启用 false 禁用
     * @platform Andorid/IOS
     * @app TigerTrade
     * @description IOS TigerTrade 6.8.1 版本新增该方法
     */
    setExitSliderEnable: function (enabled) {
        return this.call('setExitSliderEnable', { enabled: enabled });
    },
    
    /**
     * 设置是否启用webview左右滑动前进后退手势
     * @params enabled true 启用 false 禁用
     * @platform iOS
     * @app TigerTrade
     * @description iOS TigerTrade 8.0.1.0 版本新增该方法
     */
    setBackForwardNavigationGesturesEnable: function (enabled) {
        return this.call('setBackForwardNavigationGesturesEnable', { enabled: enabled });
    },
    
    /**
     * 设置页面中是否含有隐私信息，如有隐私信息，APP会在用户截图、录屏等时提醒用户注意信息泄露
     * @params flag true 页面中有隐私信息 false 页面中无隐私信息
     * @platform Android/IOS
     * @app TigerTrade/TradeUP
     * @description iOS 9.1.9 版本新增该方法
     */
    setPageSafeMode: function (flag) {
        return this.call('setPageSafeMode', { flag: flag });
    },

    /**
     * @description IOS跳转appStore Android跳转到google play
     * 
     * @platform iOS/Android
     * @app TradeUp
     */
    goAppStore: function () {
        return this.call("goAppStore");
    },

 /**
     * @description 跳转到syep首页
     * 
     * @platform iOS/Android
     */
    openSYEPPage: function () {
        return this.call("openSYEPPage");
    },

    /**
     * 下载图片到手机相册里
     * @platform Android/iOS  6.9.8.1
     * @app TigerTrade
     * @params data string  下载的内容，url或者base64，App会根据内容判断，非 http://|https:// 开头则按照base64处理
     * @params callback object  可选，如 {success: function(){}, fail: function(){}}
     * @description downloadImage
     */
    downloadImage: function (data, callback) {
        this.call('downloadImage', Object.assign({ data: data }, callback));
    },

    /**
     * @description 获取用户的App设置
     * @param {string} key 可选参数，传'greenUpRedDown'可单独返回用户设置的涨跌喜好，不传则返回所有设置项
     * @platform Android/iOS  7.0.3
     * @app TigerTrade
     */
    getAppSetting: function (key) {
        return this.call('getAppSetting', { key: key });
    },
    
    /**
     * @description 获取APP的cg内容
     * @param keys string[] 可选 需要使用的key。如果有该参数，则只返回过滤包含这些key的内容
     * @platform Android/iOS  9.1.6
     * @app TigerTrade
     */
   getCG: function (keys) {
       return this.call('getCG', keys);
   },

    /**
     * @description 开通模拟账户，从7.1.6起 新用户注册后，默认不开启模拟账户，可通过此方法开通
     * @platform iOS/Android
     * @app TigerTrade 7.1.6
     */
    openVirtualAccount: function(){
        return this.call("openVirtualAccount");
    },
    
    /**
     * @description APP 游客模式下的 h5 登录
     *
     * @param {string} url 登录成功后，跳转的 h5 地址
     * @param {object} params 登录相关参数
     * @param {string} params.invite 邀请码
     * @param {string} params.adcode 广告来源名称
     * @param {boolean} forceQuit 是否会退出到登录页
     *
     * @platform iOS | Android
     * @app TigerTrade 7.2.1.1
     */
    setUrlAfterSignIn: function(url, params, forceQuit) {
        return this.call("setUrlAfterSignIn", {url:url, params:params, forceQuit:forceQuit})
    },
    /**
     params 参考值 { invite, adcode, nextUrl, nextPage }
     nextPage 代表 native 路径，与 gonativepage 参数一致；
     nextUrl 代表网页地址。其中 nextPage优先级更高。

     forceQuit = true 会退出到登录页
     */
    login: function(params, forceQuit) {
        return this.call("login", {params:params, forceQuit:forceQuit})
    },
    
    showOnlineChat:function(show, info) {
        return this.call("showOnlineChat", {"show":show, "info":info})
    },
    
    getReCaptchaParam: function () {
        return this.call("getReCaptchaParam")
    },
    
    
    onReCaptchaResult: function(params) {
        return this.call("onReCaptchaResult", params)
    },
    
    // (在调用h5的弹框recaptcha验证时) 通过该方法通知native改变弹框尺寸
    resizeWebview: function () {
        return this.call('resizeWebview');
    },
    
    // 调用上传日志功能
    showUploadLogDialog: function () {
        return this.call('showUploadLogDialog');
    },
    
};
!(function() {
    if (!window._dsf) {
        var b = {
                _dsf: {
                    _obs: {}
                },
                _dsaf: {
                    _obs: {}
                },
                dscb: 0,
                TigerBridge: bridge,
                close: function() {
                    bridge.call("_dsb.closePage");
                },
                _handleMessageFromNative: function(a) {
                    var e = JSON.parse(a.data),
                        b = {
                            id: a.callbackId,
                            complete: !0
                        },
                        c = this._dsf[a.method],
                        d = this._dsaf[a.method],
                        h = function(a, c) {
                            b.data = a.apply(c, e);
                            bridge.call("_dsb.returnValue", b);
                        },
                        k = function(a, c) {
                            e.push(function(a, c) {
                                b.data = a;
                                b.complete = !1 !== c;
                                bridge.call("_dsb.returnValue", b);
                            });
                            a.apply(c, e);
                        };
                    if (c) h(c, this._dsf);
                    else if (d) k(d, this._dsaf);
                    else if (((c = a.method.split(".")), !(2 > c.length))) {
                        a = c.pop();
                        var c = c.join("."),
                            d = this._dsf._obs,
                            d = d[c] || {},
                            f = d[a];
                        f && "function" == typeof f
                            ? h(f, d)
                            : ((d = this._dsaf._obs),
                              (d = d[c] || {}),
                              (f = d[a]) && "function" == typeof f && k(f, d));
                    }
                }
            },
            a;
        for (a in b) window[a] = b[a];
        bridge.register("_hasJavascriptMethod", function(a, b) {
            b = a.split(".");
            if (2 > b.length) return !(!_dsf[b] && !_dsaf[b]);
            a = b.pop();
            b = b.join(".");
            return (b = _dsf._obs[b] || _dsaf._obs[b]) && !!b[a];
        });
    }
})();
