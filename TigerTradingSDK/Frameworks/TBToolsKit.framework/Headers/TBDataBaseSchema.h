//
//  TBDataBaseSchema.h
//  Stock
//
//  Created by liwt on 15/1/8.
//  Copyright (c) 2015年 com.tigerbrokers. All rights reserved.
//

#ifndef Stock_TBDataBaseSchema_h
#define Stock_TBDataBaseSchema_h


#define DATABASE_FILE_NAME @"tigerbrokers.db"
//搜索部分缓存
#define TABLE_NAME_SEARCH_HISTORY   @"search_history_fresh"
#define TABLE_NAME_SEARCH_USER_HISTORY  @"search_user_history_fresh"
#define TABLE_NAME_SEARCH_POST_HISTORY  @"search_post_history_fresh"
#define TABLE_NAME_SEARCH_FA_HISTORY  @"search_fa_history_fresh"
#define TABLE_NAME_SEARCH_PROFITANDLOST_HISTORY  @"search_profit_and_lost_history_fresh"

#define TABLE_NAME_WATCH_LIST       @"watch_list_fresh"
#define TABLE_NAME_INDICES_WATCHLIST @"indices_watchlist_fresh"
#define TABLE_NAME_MESSAGE_LIST     @"message_list"
#define TABLE_NAME_PUSH_MESSAGE     @"push_message_list"
//持仓数据库
#define TABLE_NAME_POSITION_LIST    @"position_list"
//快速体验自选数据库
#define TABLE_NAME_FAST_EXPERIENCE_WATCH_LIST   @"fast_experience_watch_list"

#define TABLE_NAME_POST_DRAFT       @"post_draft"

#define TABLE_NAME_PRICE_ALERT  @"stockPrice_alert"//股价提醒


#define SQL_CREATE_PRICEALERT_TABLE @"create table if not exists stockPrice_alert (user_symbol text primary key,market text,upTo text,upToSwitch int,downTo text,downToSwitch int,increase text,increaseSwitch int,decrease text,decreaseSwitch int,valid int)"

#define SQL_INSERT_PRICE_ALERT_FORMAT @"insert into stockPrice_alert (user_symbol,market,upTo,upToSwitch,downTo,downToSwitch,increase,increaseSwitch,decrease,decreaseSwitch,valid) values (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"

#define SQL_DELETE_PRICE_ALERT_FORMAT @"delete from stockPrice_alert where user_symbol = ?"

#define SQL_QUERY_PRICE_ALERT_FORMAT  @"select * from stockPrice_alert where user_symbol = ?"

#define SQL_UPDATE_FAST_EXPERIENCE_WATCHLIST_PRICE  @"update fast_experience_watch_list set nameCN = ?,latestPrice = ?,preClose = ?,displayLastestPrice = ?,displayChangeRate = ? where symbol = ?"

#define SQL_UPDATE_WATCHLIST_PRICE  @"update watch_list_fresh set nameCN = ?,latestPrice = ?,preClose = ?,displayLastestPrice = ?,displayChangeRate = ? where symbol = ?"


#define SQL_CREATE_POST_DRAFT_TABLE @"create table if not exists post_draft (user_symbol text primary key,title text,content text,photo blob)"
#define SQL_INSERT_POST_DRAFT_FORMAT @"insert into post_draft (user_symbol, title, content, photo) values (?, ?, ?,?)"
#define SQL_DELETE_POST_DRAFT_FORMAT @"delete from post_draft where user_symbol = ?"
#define SQL_QUERY_POST_DRAFT_FORMAT  @"select * from post_draft where user_symbol = ?"



#define SQL_CREATE_PUSH_MESSAGE_TABLE @"create table if not exists push_message_list ("\
"messageId text primary key,"\
"actionTime long,"\
"actionType long,"\
"time long,"\
"content text)"


#define SQL_CREATE_SEARCH_HISTORY_TABLE @"create table if not exists search_history_fresh ("\
"symbol text primary key,"\
"nameCN text,"\
"market text,"\
"time long,"\
"type long,"\
"halted long)"

#define SQL_CREATE_SEARCH_USER_HISTORY_TABLE @"create table if not exists search_user_history_fresh ("\
"id text primary key,"\
"name text,"\
"avatar text,"\
"vip text,"\
"time long)"

#define SQL_CREATE_SEARCH_POST_HISTORY_TABLE @"create table if not exists search_post_history_fresh ("\
"id text primary key,"\
"gmtCreate text,"\
"title text,"\
"text text,"\
"time long)"

#define SQL_CREATE_SEARCH_FA_HISTORY_TABLE @"create table if not exists search_fa_history_fresh ("\
"id long primary key,"\
"symbol text,"\
"name text,"\
"tags text,"\
"time long)"

#define SQL_CREATE_WATCH_LIST_TABLE @"create table if not exists watch_list_fresh ("\
"symbol text primary key,"\
"nameCN text,"\
"market text,"\
"secType text,"\
"latestPrice double,"\
"preClose double,"\
"time long)"

#define SQL_CREATE_INDICES_WATCHLIST_TABLE @"create table if not exists indices_watchlist_fresh ("\
"market text primary key,"\
"items text,"\
"time long)"

#define SQL_CREATE_FAST_EXPERIENCE_WATCH_LIST_TABLE @"create table if not exists fast_experience_watch_list ("\
"symbol text primary key,"\
"nameCN text,"\
"market text,"\
"secType text,"\
"latestPrice double,"\
"preClose double,"\
"time long)"

#define SQL_CREATE_POSITION_LIST_TABLE  @"create table if not exists position_list ("\
"symbol text primary key,"\
"nameCN text,"\
"market text,"\
"time long)"\

#define SQL_CREATE_MESSAGE_LIST_TABLE @"create table if not exists message_list ("\
"id long primary key,"\
"content text,"\
"timestamp long,"\
"title text,"\
"type text)"

#define SQL_QUERY_PUSH_MESSAGE_COUNT            @"select count(1) from push_message_list"
#define SQL_QUERY_PUSH_MESSAGE_FORMAT           @"select * from push_message_list order by time ASC LIMIT 50"
#define SQL_DELETE_PUSH_MESSAGE_BY_ID_FORMAT    @"delete from push_message_list where messageId = ?"
#define SQL_CLEAR_PUSH_MESSAGE_FORMAT           @"delete from push_message_list"
#define SQL_INSERT_PUSH_MESSAGE_FORMAT          @"insert into push_message_list (messageId, actionTime, actionType, time, content) values (?, ?, ?, ?, ?)"
//
#define SQL_QUERY_WATCH_LIST_COUNT              @"select count(1) from watch_list_fresh"

#define SQL_QUERY_WATCH_LIST_ALL_FORMAT         @"select * from watch_list_fresh order by time DESC"
#define SQL_QUERY_INDICES_WATCHLIST_ALL_FORMAT         @"select * from indices_watchlist_fresh order by time DESC"

#define SQL_QUERY_FAST_EXPERIENCE_WATCH_LIST_ALL_FORMAT @"select * from fast_experience_watch_list order by time DESC"
#define SQL_QUERY_WATCH_LIST_SINGLE_FORMAT      @"select * from watch_list_fresh where symbol = ?"
#define SQL_QUERY_FAST_EXPERIENCE_WATCH_LIST_SINGLE_FORMAT @"select * from fast_experience_watch_list where symbol = ?"
#define SQL_DELETE_WATCH_LIST_FORMAT            @"delete from watch_list_fresh where symbol = ?"
#define SQL_DELETE_INDICES_WATCHLIST_FORMAT            @"delete from indices_watchlist_fresh where market = ?"
#define SQL_DELETE_FAST_EXPERIENCE_WATCH_LIST_FORMAT @"delete from fast_experience_watch_list where symbol = ?"
#define SQL_INSERT_FAST_EXPERIENCE_WATCH_LIST_FORMAT @"insert into fast_experience_watch_list (symbol, nameCN, market, secType ,latestPrice , preClose, displayLastestPrice, displayChangeRate, time, name) values (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"
#define SQL_INSERT_WATCH_LIST_FORMAT            @"insert into watch_list_fresh (symbol, nameCN, market, secType, latestPrice, preClose, displayLastestPrice, displayChangeRate, time, name) values (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"
#define SQL_INSERT_INDICES_WATCHLIST_FORMAT            @"insert into indices_watchlist_fresh (market,items,time) values (?, ?, ?)"
#define SQL_CLEAR_FAST_EXPERIENCE_WATCH_LIST_FORMAT @"delete from fast_experience_watch_list"
#define SQL_CLEAR_WATCH_LIST_FORMAT             @"delete from watch_list_fresh"
//持仓操作
#define SQL_QUERY_POSITION_LIST_ALL_FORMAT      @"select * from position_list order by time DESC"
#define SQL_INSERT_POSITION_LIST_FORMAT         @"insert into position_list (symbol, nameCN, market, time) values (?, ?, ?, ?)"
#define SQL_CLEAR_POSITION_LIST_FORMAT          @"delete from position_list"

#define SQL_QUERY_SEARCH_HISTORY_COUNT_FORMAT   @"select count(1) from search_history_fresh"
#define SQL_QUERY_SEARCH_HISTORY_ALL_FORMAT     @"select * from search_history_fresh order by time DESC LIMIT 10"
#define SQL_QUERY_SEARCH_USER_HISTORY_ALL_FORMAT    @"select * from search_user_history_fresh order by time DESC LIMIT 10"
#define SQL_QUERY_SEARCH_POST_HISTORY_ALL_FORMAT    @"select * from search_post_history_fresh order by time DESC LIMIT 10"
#define SQL_QUERY_SEARCH_FA_HISTORY_ALL_FORMAT    @"select * from search_fa_history_fresh order by time DESC LIMIT 10"
#define SQL_INSERT_SEARCH_HISTORY_FORMAT        @"insert into search_history_fresh (symbol, nameCN, market, time, type, halted) values (?, ?, ?, ?, ?, ?)"
#define SQL_INSERT_SEARCH_USER_HISTORY_FORMAT   @"insert into search_user_history_fresh (id, name, avatar, vip, time) values (?, ?, ?, ?, ?)"
#define SQL_INSERT_SEARCH_POST_HISTORY_FORMAT   @"insert into search_post_history_fresh (id, gmtCreate, title, text, time) values (?,?,?,?,?)"
#define SQL_INSERT_SEARCH_FA_HISTORY_FORMAT   @"insert into search_fa_history_fresh (id, symbol, name, tags, time) values (?, ?, ?, ?, ?)"
#define SQL_CLEAR_SEARCH_HISTORY_FORMAT         @"delete from search_history_fresh"
#define SQL_CLEAR_SEARCH_USER_HISTORY_FORMAT    @"delete from search_user_history_fresh"
#define SQL_CLEAR_SEARCH_POST_HISTORY_FORMAT    @"delete from search_post_history_fresh"
#define SQL_CLEAR_SEARCH_FA_HISTORY_FORMAT   @"delete from search_fa_history_fresh"
#define SQL_DELETE_SINGLE_HISTORY_FORMAT        @"delete from search_history_fresh where symbol = ?"
#define SQL_DELETE_USER_SINGLE_HISTORY_FORMAT   @"delete from search_user_history_fresh where id = ?"
#define SQL_DELETE_POST_SINGLE_HISTORY_FORMAT   @"delete from search_post_history_fresh where id = ?"
#define SQL_DELETE_FA_SINGLE_HISTORY_FORMAT   @"delete from search_fa_history_fresh where id = ?"
#define SQL_QUERY_HISTORY_SINGLE_FORMAT         @"select * from search_history_fresh where symbol = ?"
#define SQL_QUERY_USER_HISTORY_SINGLE_FORMAT    @"select * from search_user_history_fresh where id = ?"
#define SQL_QUERY_POST_HISTORY_SINGLE_FORMAT    @"select * from search_post_history_fresh where id = ?"
#define SQL_QUERY_FA_HISTORY_SINGLE_FORMAT    @"select * from search_fa_history_fresh where id = ?"

#define SQL_QUERY_MESSAGE_LIST_ALL_FORMAT       @"select * from message_list order by timestamp DESC"
#define SQL_INSERT_MESSAGE_LIST_FORMAT          @"insert into message_list (id, title, content, timestamp, type) values (?, ?, ?, ?,?)"
#define SQL_CLEAR_MESSAGE_LIST_FORMAT           @"delete from message_list"

// 个股讨论数
#define TABLE_NAME_STOCK_DISCUSS_COUNT @"stock_discuss_count"
#define SQL_CREATE_STOCK_DISCUSS_COUNT_TABLE @"create table if not exists stock_discuss_count ("\
"symbol text primary key,"\
"requestTime text,"\
"discussCount text)"
#define SQL_DELETE_STOCK_DISCUSS_COUNT_FORMAT @"delete from stock_discuss_count where symbol = ?"
#define SQL_INSERT_STOCK_DISCUSS_COUNT_FORMAT @"insert into stock_discuss_count (symbol, requestTime, discussCount) values (?, ?, ?)"
#define SQL_QUERY_STOCK_DISCUSS_COUNT_FORMAT @"select * from stock_discuss_count where symbol = ?"

#endif
