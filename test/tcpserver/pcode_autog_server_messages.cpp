/* This file is generated by pcode_autog-1.15.9
** Copyright(c) Link.Doex, ALL RIGHTS RESERVED.
**
** Purpose: contains all protocol message definiations and codec function
**          implementations
**
*/
#include "pcode_autog_server_messages.h"

#include "pcode_autog_server_constants.h"

#include <unordered_map>

#include <functional>

#include "utils/crypto_wrapper.h"

using namespace messages;

// pcode_autog_create_header implemented by user.
extern obinarystream pcode_autog_begin_encode(uint16_t command_id, uint16_t reserved = 0x6102);

obinarystream MsgHeader::encode(void) const
{
    obinarystream obs;

    /// encode message fields.
    obs.write_i(this->length);
    obs.write_i(this->command_id);
    obs.write_i(this->version);
    obs.write_i(this->reserved);
    obs.write_i(this->reserved2);
    return std::move(obs);
}

int MsgHeader::decode(const char* data, int len)
{
    ibinarystream ibs;
    ibs.vassign(data, len);

    ibs.read_i(this->length);
    ibs.read_i(this->command_id);
    ibs.read_i(this->version);
    ibs.read_i(this->reserved);
    ibs.read_i(this->reserved2);
    return ibs.remain();
}

std::string MsgHeader::get_formated_string(void) const
{
    std::stringstream ss;
    ss << "HwpHeader:\n";
    ss << strfmt("length", this->length << '\n', '-');
    ss << strfmt("command_id", this->command_id << '\n', '-');
    ss << strfmt("version", this->version << '\n', '-');
    ss << strfmt("reserved", this->reserved << '\n', '-');
    ss << strfmt("reserved2", this->reserved2 << '\n', '-');
    return ss.str();
}

obinarystream LocalErrorResp::encode(void) const
{
    /// create message header stream.
    auto obs = pcode_autog_begin_encode(CID_LOCAL_ERROR_INFO);

    /// encode message fields.
    obs.write_i(this->error_code);
    obs.write_v(this->error_msg);
    return std::move(obs);
}

int LocalErrorResp::decode(const char* data, int len)
{
    ibinarystream ibs;
    ibs.vassign(data, len);

    ibs.read_i(this->error_code);
    ibs.read_v(this->error_msg);
    return ibs.remain();
}

std::string LocalErrorResp::get_formated_string(void) const
{
    std::stringstream ss;
    ss << "LocalErrorResp:\n";
    ss << strfmt("error_code", this->error_code << '\n', '-');
    ss << strfmt("error_msg", this->error_msg << '\n', '-');
    return ss.str();
}



obinarystream LoginReq::encode(void) const
{
    /// create message header stream.
    auto obs = pcode_autog_begin_encode(CID_LOGIN_REQ);

    /// encode message fields.
    obs.write_v(this->device_id);
    obs.write_v(this->user_name);
    obs.write_v(this->append_msg);
    return std::move(obs);
}

int LoginReq::decode(const char* data, int len)
{
    ibinarystream ibs;
    ibs.vassign(data, len);

    ibs.read_v(this->device_id);
    ibs.read_v(this->user_name);
    ibs.read_v(this->append_msg);
    return ibs.remain();
}

std::string LoginReq::get_formated_string(void) const
{
    std::stringstream ss;
    ss << "LoginReq:\n";
    ss << strfmt("device_id", this->device_id << '\n', '-');
    ss << strfmt("user_name", this->user_name << '\n', '-');
    ss << strfmt("append_msg", this->append_msg << '\n', '-');
    return ss.str();
}

obinarystream LoginResp::encode(void) const
{
    /// create message header stream.
    auto obs = pcode_autog_begin_encode(CID_LOGIN_RESP);

    /// encode message fields.
    obs.write_i(this->result);
    obs.write_i(this->user_id);
    return std::move(obs);
}

int LoginResp::decode(const char* data, int len)
{
    ibinarystream ibs;
    ibs.vassign(data, len);

    ibs.read_i(this->result);
    ibs.read_i(this->user_id);
    return ibs.remain();
}

std::string LoginResp::get_formated_string(void) const
{
    std::stringstream ss;
    ss << "LoginResp:\n";
    ss << strfmt("result", this->result << '\n', '-');
    ss << strfmt("user_id", this->user_id << '\n', '-');
    return ss.str();
}


obinarystream SoldierMovedNotify::encode(void) const
{
    /// create message header stream.
    auto obs = pcode_autog_begin_encode(CID_SOLDIER_MOVED_NOTIFY);

    /// encode message fields.
    obs.write_i(this->startp);
    obs.write_i(this->endp);
    return std::move(obs);
}

int SoldierMovedNotify::decode(const char* data, int len)
{
    ibinarystream ibs;
    ibs.vassign(data, len);

    ibs.read_i(this->startp);
    ibs.read_i(this->endp);
    return ibs.remain();
}

std::string SoldierMovedNotify::get_formated_string(void) const
{
    std::stringstream ss;
    ss << "SoldierMovedNotify:\n";
    ss << strfmt("startp", (int)this->startp << '\n', '-');
    ss << strfmt("endp", (int)this->endp << '\n', '-');
    return ss.str();
}

obinarystream SoldierRemovedNotify::encode(void) const
{
    /// create message header stream.
    auto obs = pcode_autog_begin_encode(CID_SOLDIER_REMOVED_NOTIFY);

    /// encode message fields.
    obs.write_i(this->matrixp);
    return std::move(obs);
}

int SoldierRemovedNotify::decode(const char* data, int len)
{
    ibinarystream ibs;
    ibs.vassign(data, len);

    ibs.read_i(this->matrixp);
    return ibs.remain();
}

std::string SoldierRemovedNotify::get_formated_string(void) const
{
    std::stringstream ss;
    ss << "SoldierRemovedNotify:\n";
    ss << strfmt("matrixp", (int)this->matrixp << '\n', '-');
    return ss.str();
}

obinarystream TurnOverNotify::encode(void) const
{
    /// create message header stream.
    auto obs = pcode_autog_begin_encode(CID_TURN_OVER_NOTIFY);

    /// encode message fields.
    obs.write_i(this->reserved);
    return std::move(obs);
}

int TurnOverNotify::decode(const char* data, int len)
{
    ibinarystream ibs;
    ibs.vassign(data, len);

    ibs.read_i(this->reserved);
    return ibs.remain();
}

std::string TurnOverNotify::get_formated_string(void) const
{
    std::stringstream ss;
    ss << "TurnOverNotify:\n";
    ss << strfmt("reserved", (int)this->reserved << '\n', '-');
    return ss.str();
}


obinarystream VersusDataChangedNotify::encode(void) const
{
    /// create message header stream.
    auto obs = pcode_autog_begin_encode(CID_VERSUSDATA_CHANGED_NOTIFY);

    /// encode message fields.
    obs.write_i(this->vdi);
    obs.write_i(this->value);
    return std::move(obs);
}

int VersusDataChangedNotify::decode(const char* data, int len)
{
    ibinarystream ibs;
    ibs.vassign(data, len);

    ibs.read_i(this->vdi);
    ibs.read_i(this->value);
    return ibs.remain();
}

std::string VersusDataChangedNotify::get_formated_string(void) const
{
    std::stringstream ss;
    ss << "VersusDataChangedNotify:\n";
    ss << strfmt("vdi", (int)this->vdi << '\n', '-');
    ss << strfmt("value", this->value << '\n', '-');
    return ss.str();
}

obinarystream BattleHeartbeatReq::encode(void) const
{
    /// create message header stream.
    auto obs = pcode_autog_begin_encode(CID_BATTLE_HEARTBEAT_REQ);

    /// encode message fields.
    obs.write_i(this->reserved);
    return std::move(obs);
}

int BattleHeartbeatReq::decode(const char* data, int len)
{
    ibinarystream ibs;
    ibs.vassign(data, len);

    ibs.read_i(this->reserved);
    return ibs.remain();
}

std::string BattleHeartbeatReq::get_formated_string(void) const
{
    std::stringstream ss;
    ss << "BattleHeartbeatReq:\n";
    ss << strfmt("reserved", (int)this->reserved << '\n', '-');
    return ss.str();
}

obinarystream PeerOfflineNotify::encode(void) const
{
    /// create message header stream.
    auto obs = pcode_autog_begin_encode(CID_PEER_OFFLINE_NOTIFY);

    /// encode message fields.
    obs.write_i(this->reserved);
    return std::move(obs);
}

int PeerOfflineNotify::decode(const char* data, int len)
{
    ibinarystream ibs;
    ibs.vassign(data, len);

    ibs.read_i(this->reserved);
    return ibs.remain();
}

std::string PeerOfflineNotify::get_formated_string(void) const
{
    std::stringstream ss;
    ss << "PeerOfflineNotify:\n";
    ss << strfmt("reserved", (int)this->reserved << '\n', '-');
    return ss.str();
}

obinarystream PeerOnlineNotify::encode(void) const
{
    /// create message header stream.
    auto obs = pcode_autog_begin_encode(CID_PEER_ONLINE_NOTIFY);

    /// encode message fields.
    obs.write_i(this->reserved);
    return std::move(obs);
}

int PeerOnlineNotify::decode(const char* data, int len)
{
    ibinarystream ibs;
    ibs.vassign(data, len);

    ibs.read_i(this->reserved);
    return ibs.remain();
}

std::string PeerOnlineNotify::get_formated_string(void) const
{
    std::stringstream ss;
    ss << "PeerOnlineNotify:\n";
    ss << strfmt("reserved", (int)this->reserved << '\n', '-');
    return ss.str();
}

obinarystream RealtimeBattleInfoNotify::encode(void) const
{
    /// create message header stream.
    auto obs = pcode_autog_begin_encode(CID_REALTIME_BATTLE_INFO_NOTIFY);

    auto offset = obs.length(); // offset for body compress.

    /// encode message fields.
    obs.write_i(this->receiver_first);
    obs.write_i(this->opside);
    obs.write_i(this->mode);
    obs.write_i(this->rounds);
    obs.write_i(this->rounds_limit);
    obs.write_i(this->steps);
    obs.write_i(this->optime);
    obs.write_v(this->sender_info.user_name);
    obs.write_i(this->sender_info.equip_id);
    obs.write_i(this->sender_info.hero_id);
    obs.write_i(this->sender_info.hero_lv);
    obs.write_i(this->sender_info.hero_hp);
    obs.write_i(this->sender_info.hero_mp);
    obs.write_i(this->sender_info.idles);
    obs.write_i(this->sender_info.wrecord);
    obs.write_v(this->sender_info.append_data);
    if(true)
    {
        obs.write_v(this->receiver_info.user_name);
        obs.write_i(this->receiver_info.equip_id);
        obs.write_i(this->receiver_info.hero_id);
        obs.write_i(this->receiver_info.hero_lv);
        obs.write_i(this->receiver_info.hero_hp);
        obs.write_i(this->receiver_info.hero_mp);
        obs.write_i(this->receiver_info.idles);
        obs.write_i(this->receiver_info.wrecord);
        obs.write_v(this->receiver_info.append_data);
    }
    // obs.compress(offset); // do body compress.

    return std::move(obs);
}

int RealtimeBattleInfoNotify::decode(const char* data, int len)
{
    ibinarystream ibs;
    //auto uncompr = crypto::zlib::abi::inflate(unmanaged_string(data, len)); 
    //ibs.vassign(uncompr.data(), uncompr.size());
    ibs.vassign(data, len);

    ibs.read_i(this->receiver_first);
    ibs.read_i(this->opside);
    ibs.read_i(this->mode);
    ibs.read_i(this->rounds);
    ibs.read_i(this->rounds_limit);
    ibs.read_i(this->steps);
    ibs.read_i(this->optime);
    ibs.read_v(this->sender_info.user_name);
    ibs.read_i(this->sender_info.equip_id);
    ibs.read_i(this->sender_info.hero_id);
    ibs.read_i(this->sender_info.hero_lv);
    ibs.read_i(this->sender_info.hero_hp);
    ibs.read_i(this->sender_info.hero_mp);
    ibs.read_i(this->sender_info.idles);
    ibs.read_i(this->sender_info.wrecord);
    ibs.read_v(this->sender_info.append_data);
    if(true)
    {
        ibs.read_v(this->receiver_info.user_name);
        ibs.read_i(this->receiver_info.equip_id);
        ibs.read_i(this->receiver_info.hero_id);
        ibs.read_i(this->receiver_info.hero_lv);
        ibs.read_i(this->receiver_info.hero_hp);
        ibs.read_i(this->receiver_info.hero_mp);
        ibs.read_i(this->receiver_info.idles);
        ibs.read_i(this->receiver_info.wrecord);
        ibs.read_v(this->receiver_info.append_data);
    }
    return ibs.remain();
}

std::string RealtimeBattleInfoNotify::get_formated_string(void) const
{
    std::stringstream ss;
    ss << "RealtimeBattleInfoNotify:\n";
    ss << strfmt("receiver_first", (int)this->receiver_first << '\n', '-');
    ss << strfmt("opside", (int)this->opside << '\n', '-');
    ss << strfmt("mode", (int)this->mode << '\n', '-');
    ss << strfmt("rounds", this->rounds << '\n', '-');
    ss << strfmt("rounds_limit", this->rounds_limit << '\n', '-');
    ss << strfmt("steps", this->steps << '\n', '-');
    ss << strfmt("optime", this->optime << '\n', '-');
    ss << strfmt("user_name", this->sender_info.user_name << '\n', '-');
    ss << strfmt("equip_id", this->sender_info.equip_id << '\n', '-');
    ss << strfmt("hero_id", this->sender_info.hero_id << '\n', '-');
    ss << strfmt("hero_lv", this->sender_info.hero_lv << '\n', '-');
    ss << strfmt("hero_hp", this->sender_info.hero_hp << '\n', '-');
    ss << strfmt("hero_mp", this->sender_info.hero_mp << '\n', '-');
    ss << strfmt("idles", this->sender_info.idles << '\n', '-');
    ss << strfmt("wrecord", this->sender_info.wrecord << '\n', '-');
    ss << strfmt("append_data", this->sender_info.append_data << '\n', '-');
    if(true)
    {
        ss << strfmt("user_name", this->receiver_info.user_name << '\n', '-');
        ss << strfmt("equip_id", this->receiver_info.equip_id << '\n', '-');
        ss << strfmt("hero_id", this->receiver_info.hero_id << '\n', '-');
        ss << strfmt("hero_lv", this->receiver_info.hero_lv << '\n', '-');
        ss << strfmt("hero_hp", this->receiver_info.hero_hp << '\n', '-');
        ss << strfmt("hero_mp", this->receiver_info.hero_mp << '\n', '-');
        ss << strfmt("idles", this->receiver_info.idles << '\n', '-');
        ss << strfmt("wrecord", this->receiver_info.wrecord << '\n', '-');
        ss << strfmt("append_data", this->receiver_info.append_data << '\n', '-');
    }
    return ss.str();
}

static char s_allocp[16384]; // static alloc memory.
static std::unordered_map<int, std::function<MsgBase*(void)>> s_table_message_ctor;
MsgBase* messages::temp_create_message(int command_id)
{
    auto target = s_table_message_ctor.find(command_id);
    if(target != s_table_message_ctor.end())
        return (target->second)();
    assert(false);
    return nullptr;
}

static int internal_message_ctor_table_preinit(void)
{
    s_table_message_ctor[CID_LOCAL_ERROR_INFO]= []()->MsgBase*{ return new(s_allocp) LocalErrorResp(); };
    s_table_message_ctor[CID_LOGIN_REQ]= []()->MsgBase*{ return new(s_allocp) LoginReq(); };
    s_table_message_ctor[CID_LOGIN_RESP]= []()->MsgBase*{ return new(s_allocp) LoginResp(); };
    s_table_message_ctor[CID_SOLDIER_MOVED_NOTIFY]= []()->MsgBase*{ return new(s_allocp) SoldierMovedNotify(); };
    s_table_message_ctor[CID_SOLDIER_REMOVED_NOTIFY]= []()->MsgBase*{ return new(s_allocp) SoldierRemovedNotify(); };
    s_table_message_ctor[CID_TURN_OVER_NOTIFY]= []()->MsgBase*{ return new(s_allocp) TurnOverNotify(); };
    s_table_message_ctor[CID_VERSUSDATA_CHANGED_NOTIFY]= []()->MsgBase*{ return new(s_allocp) VersusDataChangedNotify(); };
    s_table_message_ctor[CID_BATTLE_HEARTBEAT_REQ]= []()->MsgBase*{ return new(s_allocp) BattleHeartbeatReq(); };
    s_table_message_ctor[CID_PEER_OFFLINE_NOTIFY]= []()->MsgBase*{ return new(s_allocp) PeerOfflineNotify(); };
    s_table_message_ctor[CID_PEER_ONLINE_NOTIFY]= []()->MsgBase*{ return new(s_allocp) PeerOnlineNotify(); };
    s_table_message_ctor[CID_REALTIME_BATTLE_INFO_NOTIFY]= []()->MsgBase*{ return new(s_allocp) RealtimeBattleInfoNotify(); };
    return 0;
}

static const int __TABLE_INIT_PLACE_HOLDER = internal_message_ctor_table_preinit();
