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

#ifndef LFGPackets_h__
#define LFGPackets_h__

#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace LFG
    {
        struct LFGBlackListSlot
        {
            LFGBlackListSlot() { }
            LFGBlackListSlot(uint32 slot, uint32 reason, int32 subReason1, int32 subReason2) : Slot(slot), Reason(reason), SubReason1(subReason1), SubReason2(subReason2) { }

            uint32 Slot = 0;
            uint32 Reason = 0;
            int32 SubReason1 = 0;
            int32 SubReason2 = 0;
        };

        struct LFGBlackList
        {
            Optional<ObjectGuid> PlayerGuid;
            std::vector<LFGBlackListSlot> Slot;
        };

        struct LfgPlayerQuestRewardItem 
        {
            LfgPlayerQuestRewardItem() { }
            LfgPlayerQuestRewardItem(int32 itemId, int32 quantity) : ItemID(itemId), Quantity(quantity) { }

            int32 ItemID = 0;
            int32 Quantity = 0;
        };

        struct LfgPlayerQuestRewardCurrency
        {
            LfgPlayerQuestRewardCurrency() { }
            LfgPlayerQuestRewardCurrency(int32 currencyID, int32 quantity) : CurrencyID(currencyID), Quantity(quantity) { }

            int32 CurrencyID = 0;
            int32 Quantity = 0;
        };

        struct LfgPlayerQuestReward
        {
            uint32 Mask = 0;
            int32 RewardMoney = 0;
            int32 RewardXP = 0;
            std::vector<LfgPlayerQuestRewardItem> Item;
            std::vector<LfgPlayerQuestRewardCurrency> Currency;
            std::vector<LfgPlayerQuestRewardCurrency> BonusCurrency;
            Optional<int32> RewardSpellID;
            Optional<int32> Unused1;
            Optional<uint64> Unused2;
            Optional<int32> Honor;
        };

        struct LfgPlayerDungeonInfo
        {
            uint32 Slot = 0;
            int32 CompletionQuantity = 0;
            int32 CompletionLimit = 0;
            int32 CompletionCurrencyID = 0;
            int32 SpecificQuantity = 0;
            int32 SpecificLimit = 0;
            int32 OverallQuantity = 0;
            int32 OverallLimit = 0;
            int32 PurseWeeklyQuantity = 0;
            int32 PurseWeeklyLimit = 0;
            int32 PurseQuantity = 0;
            int32 PurseLimit = 0;
            int32 Quantity = 0;
            uint32 CompletedMask = 0;
            uint32 EncounterMask = 0;
            bool FirstReward = false;
            bool ShortageEligible = false;
            LfgPlayerQuestReward Rewards;
            std::vector<LfgPlayerQuestReward> ShortageReward;
        };

        struct RideTicket
        {
            ObjectGuid RequesterGuid;
            int32 Id = 0;
            int32 Type = 0;
            uint32 Time = 0;
        };

        class DFGetSystemInfo final : public ClientPacket
        {
        public:
            DFGetSystemInfo(WorldPacket&& packet) : ClientPacket(CMSG_DF_GET_SYSTEM_INFO, std::move(packet)) { }

            void Read() override;

            uint8 PartyIndex = 0;
            bool Player = false;
        };

        class LfgPlayerInfo final : public ServerPacket
        {
        public:
            LfgPlayerInfo() : ServerPacket(SMSG_LFG_PLAYER_INFO) { }

            WorldPacket const* Write() override;

            ObjectGuid RequesterGuid;
            LFGBlackList BlackList;
            std::vector<LfgPlayerDungeonInfo> Dungeon;
        };
    }
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::RideTicket& ticket);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::RideTicket const& ticket);

#endif // LFGPackets_h__
