/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "LFGPackets.h"

void WorldPackets::LFG::DFGetSystemInfo::Read()
{
    Player = _worldPacket.ReadBit();
    _worldPacket >> PartyIndex;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::RideTicket& ticket)
{
    data >> ticket.RequesterGuid;
    data >> ticket.Id;
    data >> ticket.Type;
    data >> ticket.Time;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::RideTicket const& ticket)
{
    data << ticket.RequesterGuid;
    data << int32(ticket.Id);
    data << int32(ticket.Type);
    data << uint32(ticket.Time);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGBlackListSlot const& lfgBlackListSlot)
{
    data << uint32(lfgBlackListSlot.Slot);
    data << uint32(lfgBlackListSlot.Reason);
    data << uint32(lfgBlackListSlot.SubReason1);
    data << uint32(lfgBlackListSlot.SubReason2);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGBlackList const& blackList)
{
    data.WriteBit(blackList.PlayerGuid.is_initialized());
    data << uint32(blackList.Slot.size());
    if (blackList.PlayerGuid)
        data << *blackList.PlayerGuid;

    for (WorldPackets::LFG::LFGBlackListSlot const& slot : blackList.Slot)
        data << slot;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestRewardItem const& playerQuestRewardItem)
{
    data << int32(playerQuestRewardItem.ItemID);
    data << int32(playerQuestRewardItem.Quantity);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestRewardCurrency const& playerQuestRewardCurrency)
{
    data << int32(playerQuestRewardCurrency.CurrencyID);
    data << int32(playerQuestRewardCurrency.Quantity);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestReward const& playerQuestReward)
{
    data << uint32(playerQuestReward.Mask);
    data << int32(playerQuestReward.RewardMoney);
    data << int32(playerQuestReward.RewardXP);
    data << uint32(playerQuestReward.Item.size());
    data << uint32(playerQuestReward.Currency.size());
    data << uint32(playerQuestReward.BonusCurrency.size());

    for (WorldPackets::LFG::LfgPlayerQuestRewardItem const& item : playerQuestReward.Item)
        data << item;

    for (WorldPackets::LFG::LfgPlayerQuestRewardCurrency const& currency : playerQuestReward.Currency)
        data << currency;

    for (WorldPackets::LFG::LfgPlayerQuestRewardCurrency const& bonusCurrency : playerQuestReward.BonusCurrency)
        data << bonusCurrency;
    
    data.WriteBit(playerQuestReward.RewardSpellID.is_initialized());
    if (playerQuestReward.RewardSpellID)
        data << int32(*playerQuestReward.RewardSpellID);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerDungeonInfo const& playerDungeonInfo)
{
    data << uint32(playerDungeonInfo.Slot);
    data << int32(playerDungeonInfo.CompletionQuantity);
    data << int32(playerDungeonInfo.CompletionLimit);
    data << int32(playerDungeonInfo.CompletionCurrencyID);
    data << int32(playerDungeonInfo.SpecificQuantity);
    data << int32(playerDungeonInfo.SpecificLimit);
    data << int32(playerDungeonInfo.OverallQuantity);
    data << int32(playerDungeonInfo.OverallLimit);
    data << int32(playerDungeonInfo.PurseWeeklyQuantity);
    data << int32(playerDungeonInfo.PurseWeeklyLimit);
    data << int32(playerDungeonInfo.PurseQuantity);
    data << int32(playerDungeonInfo.PurseLimit);
    data << int32(playerDungeonInfo.Quantity);
    data << uint32(playerDungeonInfo.CompletedMask);

    data << uint32(playerDungeonInfo.ShortageReward.size());
    data << playerDungeonInfo.Rewards;
    // for (WorldPackets::LFG::LfgPlayerQuestReward const& shortageReward : playerDungeonInfo.ShortageReward)
    //     data << shortageReward;

    data.WriteBit(playerDungeonInfo.FirstReward);
    data.WriteBit(playerDungeonInfo.ShortageEligible);
    data.FlushBits();
    
    return data;
}

WorldPacket const* WorldPackets::LFG::LfgPlayerInfo::Write()
{
    _worldPacket << uint32(Dungeon.size());
    _worldPacket << BlackList;
    for (LfgPlayerDungeonInfo const& playerDungeonInfo : Dungeon)
        _worldPacket << playerDungeonInfo;

    return &_worldPacket;
}
